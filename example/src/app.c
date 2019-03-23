#include <stdlib.h>
#include <automata\automata_window.h>
#include <automata\automata_input.h>
#include <automata\automata_image.h>

int main() {
	/* variables */
	AutomataImage windowIcon = { NULL, 0, 0, 0 };

	/* intialize application */
	automataWindowInit();
	automataWindowCreate(1280, 720, "Automata Framework");
	automataInputInit(automataWindowGetWindow());

	/* set window icon*/
	automataImageLoad(&windowIcon, "sprites/icon.png");
	automataWindowSetIcon(windowIcon.width, windowIcon.height, windowIcon.pixels);
	automataImageUnload(&windowIcon);

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