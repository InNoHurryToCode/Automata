#include <stdlib.h>
#include <automata\automata_window.h>
#include <automata\automata_input.h>
#include <automata\automata_image.h>

int main() {
	/* variables */
	AutomataImage *windowIcon = NULL;

	/* intialize application */
	automataWindowInit();
	automataWindowCreate(1280, 720, "Automata Engine");

	/* set window icon*/
	windowIcon = automataImageLoad("sprites/icon.png");

	if (windowIcon) {
		automataWindowSetIcon(windowIcon->width, windowIcon->height, windowIcon->pixels);
		automataImageUnload(windowIcon);
	}
	
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