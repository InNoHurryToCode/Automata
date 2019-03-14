#include <stdio.h>
#include <stdlib.h>
#include "automata_const.h"
#include "automata_window.h"

int main() {
	/* intialize application */
	printf("Automata Engine\n");
	printf("Version: %c%d.%d.%d\n", AUTOMATA_VERSION_TYPE, AUTOMATA_VERSION_MAJOR, AUTOMATA_VERSION_MINOR, AUTOMATA_VERSION_FIX);

	automataWindowInit();
	automataWindowCreate(1280, 720, "Automata Engine");

	/* application loop */
	while (automataWindowIsAlive) {
		automataWindowUpdate();
	}

	/* terminate application */
	automataWindowTerminate();
	return EXIT_SUCCESS;
}