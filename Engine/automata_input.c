#include <stdio.h>
#include <glfw/glfw3.h>
#include "automata_input.h"

static char keys[AUTOMATA_INPUT_KEYS_AMOUNT] = { 0 };
static double axes[AUTOMATA_INPUT_AXES_AMOUNT] = { 0.0 };
static char gamepads[AUTOMATA_INPUT_GAMEPAD_AMOUNT] = { 0 };

void automataInputUpdate() {
	automataInputGamepadButtonCallback();
	automataInputGamepadAxisCalback();
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

int *automataInputGetGamepadState(AutomataInputGamepad gamepad) {
	if (gamepad >= AUTOMATA_INPUT_GAMEPAD_AMOUNT) {
		return;
	}

	/* get gamepad state */
	return gamepads[gamepad];
}

const char* automataInputGetGamepadName(AutomataInputGamepad gamepad) {
	if (gamepad >= AUTOMATA_INPUT_GAMEPAD_AMOUNT) {
		return NULL;
	}

	/* get gamepad state */
	return glfwGetJoystickName(gamepad);
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

void automataInputGamepadAxisCalback() {
	int i = 0;
	int j = 0;
	int axesCount = 0;
	float* gamepadAxes = NULL;

	while (i <= AUTOMATA_INPUT_LAST_GAMEPAD) {
		if (automataInputGetGamepadState(i)) {
			gamepadAxes = glfwGetJoystickAxes(i, &axesCount);

			while (j < axesCount) {
				axes[i * j + 2] = gamepadAxes[j];
				++j;
			}
		}

		++i;
	}
}

void automataInputGamepadButtonCallback() {
	int i = 0;
	int j = 0;
	int segment = 0;
	int buttonsCount = 0;
	unsigned char* gamepadButtons = NULL;

	while (i <= AUTOMATA_INPUT_LAST_GAMEPAD) {
		segment = i * AUTOMATA_INPUT_GAMEPAD_BUTTONS_COUNT + AUTOMATA_INPUT_LAST_MOUSE_BUTTON + 1;

		if (automataInputGetGamepadState(i)) {
			gamepadButtons = glfwGetJoystickButtons(i, &buttonsCount);

			while (j < AUTOMATA_INPUT_GAMEPAD_BUTTONS_COUNT) {
				if (j >= buttonsCount) {
					keys[j + segment + 1] = 0;
				} else {
					keys[j + segment + 1] = gamepadButtons[j];

					printf("%d: %d\n", j, gamepadButtons[j]);
				}

				++j;
			}
		}

		++i;
	}
}

void automataInputGamepadConnectedCallback(int joy, int event) {
	if (event == GLFW_CONNECTED) {
		gamepads[joy] = 1;
	}

	if (event == GLFW_DISCONNECTED) {
		gamepads[joy] = 0;
	}
} 