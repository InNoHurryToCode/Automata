#include <stdlib.h>
#include <automata\automata_file.h>
#include <automata\automata_input.h>
#include <automata\automata_window.h>

int main() {
	/* variables */
	AutomataImageFile windowIcon = { 0, 0, 0, NULL };

	/* intialize application */
	automataWindowInit();
	automataWindowCreate(1280, 720, "Automata Framework");
	automataInputInit(automataWindowGetWindow());

	/* set window icon*/
	automataFileLoadImage(&windowIcon, "sprites/icon.png");
	automataWindowSetIcon(windowIcon.width, windowIcon.height, windowIcon.pixels);
	automataFileUnloadImage(&windowIcon);

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