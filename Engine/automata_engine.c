#include <stdio.h>
#include <stdlib.h>
#include "automata_input.h"
#include "automata_window.h"

int main() {
	/* intialize application */
	automataWindowInit();
	automataWindowCreate(1280, 720, "Automata Engine");

	/* application loop */
	while (automataWindowIsAlive()) {
		automataWindowUpdate();
		automataInputUpdate();

		if (automataInputGetKey(AUTOMATA_KEY_ESC)) {
			automataWindowClose();
		}

		printf("1: %d\n", automataInputGetKey(AUTOMATA_KEY_GAMEPAD_1_17));
		printf("2: %d\n", automataInputGetKey(AUTOMATA_KEY_GAMEPAD_2_17));

		automataWindowSwapBuffers();
	}

	/* terminate application */
	automataWindowTerminate();
	return EXIT_SUCCESS;
}