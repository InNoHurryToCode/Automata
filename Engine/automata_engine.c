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
		/*automataInputUpdate();*/

		printf("key pressed: %d\n", automataInputDetectKey());
		if (automataInputGetKey(AUTOMATA_KEY_GAMEPAD_1_17 /*AUTOMATA_KEY_ESC*/)) {
			automataWindowClose();
		}

		automataWindowSwapBuffers();
	}

	/* terminate application */
	automataWindowTerminate();
	return EXIT_SUCCESS;
}