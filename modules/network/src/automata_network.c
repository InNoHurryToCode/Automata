#include <stdlib.h>
#include <winsock2.h>
#include "../include/automata/automata_network.h"

/* general */
static WSADATA wsaData;

typedef struct addrinfo AutomataNetworkType;

typedef struct AutomataNetworkServer {
	SOCKET masterSocket;
	SOCKET clientSockets[AUTOMATA_NETWORK_SERVER_MAX_CLIENTS];
	struct sockaddr_in masterAddress;
	struct addrinfo masterSocketType;
} AutomataNetworkServer;

void automataNetworkInit() {
	/* initialize networking module */
	WSAStartup(MAKEWORD(2, 2), &wsaData);
}

void automataNetworkTerminate() {
	/* terminate networking module */
	WSACleanup();
}

void automataNetworkCloseSocket(SOCKET socket) {
	closesocket(socket);
}

void automataNetworkReceivePacket(SOCKET targetSocket, char *buffer) {
	recv(targetSocket, buffer, sizeof(buffer), 0);
}

void automataNetworkSentPacket(SOCKET targetSocket, const char *buffer) {
	send(targetSocket, buffer, sizeof(buffer), 0);
}

void automataNetworkCreateServer(AutomataNetworkServer *server, AutomataNetworkType socketType) {
	if (server) {
		return;
	}
	
	/* allocate memory */
	memset(server, 0, sizeof(server));
	
	/* create socket */
	socket(socketType.ai_family, socketType.ai_socktype, socketType.ai_protocol);

	if (server->masterSocket == INVALID_SOCKET) {
		automataNetworkTerminate();
		return;
	}

	/* bind socket */
	server->masterAddress.sin_family = AF_INET;
	server->masterAddress.sin_addr.s_addr = inet_addr(AUTOMATA_NETWORK_DEFAULT_IP);
	server->masterAddress.sin_port = htons(AUTOMATA_NETWORK_DEFAULT_PORT);
	
	if (bind(server->masterSocket, (struct sockaddr *)&server->masterAddress, sizeof(server->masterAddress)) == SOCKET_ERROR) {
		automataNetworkCloseSocket(server->masterSocket);
		automataNetworkTerminate();
		return;
	}

	/* listen to socket */
	if (listen(server->masterSocket, AUTOMATA_NETWORK_DEFAULT_CONNECTIONS) == SOCKET_ERROR) {
		automataNetworkCloseSocket(server->masterSocket);
		automataNetworkTerminate();
		return;
	}
}

void automataNetworkUpdateServer(AutomataNetworkServer *server) {
	int i = 0;
	int activity = 0;
	fd_set socketDescriptors;
	SOCKET currentClientSocket = 0;
	SOCKET newClientSocket = 0;
	
	if (!server) {
		return;
	}
	
	/* clear socket descriptors */
	FD_ZERO(&socketDescriptors);

	/* add server to socket descriptors */
	FD_SET(server->masterSocket, &socketDescriptors);

	/* add client sockets to socket descriptors */
	while (i < AUTOMATA_NETWORK_SERVER_MAX_CLIENTS) {
		currentClientSocket = server->clientSockets[i];
		
		if (currentClientSocket > 0) {
			FD_SET(currentClientSocket, &socketDescriptors);
		}

		++i;
	}

	/* check for activity */
	activity = select(0, &socketDescriptors, NULL, NULL, NULL);

	if (activity == SOCKET_ERROR) {
		automataNetworkTerminate();
	}

	/* incoming connection */
	if (FD_ISSET(server->masterSocket, &socketDescriptors)) {
		/* accept connection */
		newClientSocket = accept(server->masterSocket, NULL, NULL);

		if (newClientSocket < 0) {
			automataNetworkTerminate();
		}

		/* add new socket to array of sockets */
		i = 0;

		while (i < AUTOMATA_NETWORK_SERVER_MAX_CLIENTS) {
			if (server->clientSockets[i] == 0) {
				server->clientSockets[i] = newClientSocket;
				break;
			}

			++i;
		}
	}

	/* check for disconnected sockets */
	/* TODO */
}

void automataNetworkSetTCPType(AutomataNetworkType *type) {
	if (!type) {
		return;
	}
	
	/* set type to TCP */
	type->ai_family = AF_INET;
	type->ai_socktype = SOCK_STREAM;
	type->ai_protocol = IPPROTO_TCP;
}

void automataNetworkSetUDPType(AutomataNetworkType *type) {
	if (!type) {
		return;
	}

	/* set type to TCP */
	type->ai_family = AF_INET;
	type->ai_socktype = SOCK_DGRAM;
	type->ai_protocol = IPPROTO_UDP;
}