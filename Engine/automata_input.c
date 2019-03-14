#include <glfw/glfw3.h>
#include "automata_const.h"
#include "automata_input.h"

static char keys[AUTOMATA_INPUT_KEYS_TOTAL_AMOUNT] = { 0 };
static double mouseX = 0.0;
static double mouseY = 0.0;

int automataInputGetKey(int key) {
	if (key < 0 || key >= AUTOMATA_INPUT_KEYS_TOTAL_AMOUNT) {
		return 0;
	}
	
	/* get key state */
	return keys[key];
}

int automataInputGetAnyKey() {
	/* get any pressed key */
	unsigned int i = 0;

	while (i < AUTOMATA_INPUT_KEYS_TOTAL_AMOUNT) {
		if (keys[i]) {
			return keys[i];
		}
	}

	return -1;
}

double automataInputGetMouseX() {
	/* get mouse x position */
	return mouseX;
}

double automataInputGetMouseY() {
	/* get mouse y position */
	return mouseY;
}

void automataInputKeyboardKeyCallback(GLFWwindow* glfwWindow, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_UNKNOWN) {
		return;
	}
	
	/* register keyboard key state */
	if (action == GLFW_PRESS) {
		keys[key] = 1;
	} else {
		keys[key] = 0;
	}
}

void automataInputMouseButtonCallback(GLFWwindow* glfwWindow, int button, int action, int mods) {
	/* register keyboard key state */
	if (action == GLFW_PRESS) {
		keys[button + AUTOMATA_INPUT_KEYBOARD_KEYS_AMOUNT] = 1;
	} else {
		keys[button + AUTOMATA_INPUT_KEYBOARD_KEYS_AMOUNT] = 0;
	}
}

void automataInputMousePositionCallback(GLFWwindow* glfwWindow, double xpos, double ypos) {
	/* register mouse input */
	mouseX = xpos;
	mouseY = ypos;
}