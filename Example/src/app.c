#include <stdlib.h>
#include <automata\automata_input.h>
#include <automata\automata_window.h>

int main() {
	/* intialize application */
	automataWindowInit();
	automataWindowCreate(1280, 720, "Automata Engine");
	automataInputInit(automataWindowGetWindow());

	/* application loop */
	while (automataWindowIsAlive()) {
		automataWindowUpdate();
		automataInputUpdate();

		if (automataInputGetKey(AUTOMATA_KEY_ESC)) {
			automataWindowClose();
		}

		automataWindowSwapBuffers();
	}

	/* terminate application */
	automataWindowTerminate();
	return EXIT_SUCCESS;
}