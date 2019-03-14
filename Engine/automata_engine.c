#include <stdio.h>
#include <stdlib.h>
#include "automata_const.h"
#include "automata_window.h"

int main() {
	/* intialize application */
	automataWindowInit();
	automataWindowCreate(1280, 720, "Automata Engine");

	/* application loop */
	while (automataWindowIsAlive()) {
		automataWindowUpdate();
	}

	/* terminate application */
	automataWindowTerminate();
	return EXIT_SUCCESS;
}