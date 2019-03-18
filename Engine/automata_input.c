#include <glfw/glfw3.h>
#include "automata_const.h"
#include "automata_input.h"

static char keys[AUTOMATA_INPUT_KEYS_AMOUNT] = { 0 };
static double axis[AUTOMATA_INPUT_AXIS_AMOUNT] = { 0.0 };

int automataInputGetKey(AutomataInputKey key) {
	if (key < 0 || key >= AUTOMATA_INPUT_KEYS_AMOUNT) {
		return 0;
	}
	
	/* get key state */
	return keys[key];
}

int automataInputGetAnyKey() {
	/* get any pressed key */
	unsigned int i = 0;

	while (i < AUTOMATA_INPUT_KEYS_AMOUNT) {
		if (keys[i]) {
			return keys[i];
		}
	}

	return 0;
}

double automataInputGetAxis(AutomataInputAxis key) {
	if (key < 0 || key >= AUTOMATA_INPUT_AXIS_AMOUNT) {
		return 0;
	}
	
	/* get axis */
	return axis[key];
}

void automataInputKeyboardKeyCallback(GLFWwindow *glfwWindow, int key, int scancode, int action, int mods) {
	if (key == AUTOMATA_KEY_UNKNOWN) {
		return;
	}
	
	/* register keyboard key state */
	if (action == GLFW_PRESS) {
		keys[key] = 1;
	} else {
		keys[key] = 0;
	}
}

void automataInputMouseButtonCallback(GLFWwindow *glfwWindow, int button, int action, int mods) {
	/* register keyboard key state */
	if (action == GLFW_PRESS) {
		keys[button + (AUTOMATA_INPUT_LAST_KEYBOARD_KEY + 1)] = 1;
	} else {
		keys[button + (AUTOMATA_INPUT_LAST_KEYBOARD_KEY + 1)] = 0;
	}
}

void automataInputMousePositionCallback(GLFWwindow *glfwWindow, double xpos, double ypos) {
	/* register mouse input */
	axis[AUTOMATA_AXIS_MOUSE_X] = xpos;
	axis[AUTOMATA_AXIS_MOUSE_Y] = ypos;
}