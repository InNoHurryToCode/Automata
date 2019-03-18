#include <stdio.h>
#include <glfw/glfw3.h>
#include "automata_input.h"

static char keys[AUTOMATA_INPUT_KEYS_AMOUNT] = { 0 };
static double axes[AUTOMATA_INPUT_AXES_AMOUNT] = { 0.0 };

void automataInputUpdate() {
	automataInputGamepadButtonCallback();
}

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

		++i;
	}

	return 0;
}

AutomataInputKey automataInputDetectKey() {
	/* get which key is pressed */
	unsigned int i = 0;

	while (i < AUTOMATA_INPUT_KEYS_AMOUNT) {
		if (keys[i]) {
			return i;
		}

		++i;
	}

	return AUTOMATA_KEY_UNKNOWN;
}

double automataInputGetAxis(AutomataInputAxis axis) {
	if (axis < 0 || axis >= AUTOMATA_INPUT_AXES_AMOUNT) {
		return 0;
	}
	
	/* get axis */
	return axes[axis];
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
	axes[AUTOMATA_AXIS_MOUSE_X] = xpos;
	axes[AUTOMATA_AXIS_MOUSE_Y] = ypos;
}

/* BROKEN CODE, NEEDS FIX */
void automataInputGamepadButtonCallback() {
	int i = 0;
	int j = 0;
	GLFWgamepadstate state;

	while (i <= GLFW_JOYSTICK_LAST) {
		/* gamepad detected */
		if (glfwGetGamepadState(i, &state)) {
			/* get button states */
			/*
			while (j <= GLFW_GAMEPAD_BUTTON_LAST) {
				keys[j + (AUTOMATA_INPUT_LAST_MOUSE_BUTTON + (GLFW_GAMEPAD_BUTTON_LAST * i + 1))] = state.buttons[j];
				++j;
			}
			*/

			/* get axes states */
			/*
			i = 0;

			while (j <= GLFW_GAMEPAD_AXIS_LAST) {
				axes[j + (GLFW_GAMEPAD_AXIS_LAST * i + 3)] = state.axes[j];
				++j;
			}
			*/
		}

		++i;
	}
}

/* BROKEN CODE, NEEDS FIX */
void automataInputGamepadConnectedCallback(int joy, int event) {
	if (event == GLFW_CONNECTED) {
		/* code here */
	}

	if (event == GLFW_DISCONNECTED) {
		/* code here */
	}
} 