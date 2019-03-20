#include "automata_input.h"

static char keys[AUTOMATA_INPUT_KEYS_AMOUNT] = { 0 };
static double axes[AUTOMATA_INPUT_AXES_AMOUNT] = { 0.0 };
static char gamepads[AUTOMATA_INPUT_GAMEPADS_AMOUNT] = { 0 };

static void automataInputKeyboardKeyCallback(GLFWwindow *glfwWindow, int key, int scancode, int action, int mods) {
	if (key == AUTOMATA_KEY_UNKNOWN || key > AUTOMATA_INPUT_LAST_KEYBOARD_KEY) {
		return;
	}
	
	/* register keyboard key state */
	if (action == GLFW_PRESS) {
		keys[key] = 1;
	} else {
		keys[key] = 0;
	}
}

static void AutomataInputMouseScrollCallback(GLFWwindow *glfwWindow, double xoffset, double yoffset) {
	/* register scroll input */
	axes[AUTOMATA_AXIS_MOUSE_SCROLL] = yoffset;
}

static void automataInputMouseButtonCallback(GLFWwindow *glfwWindow, int button, int action, int mods) {
	if (button < 0 || button >= AUTOMATA_INPUT_MOUSE_AXES_AMOUNT) {
		return;
	}
	
	/* register keyboard key state */
	if (action == GLFW_PRESS) {
		keys[button + (AUTOMATA_INPUT_LAST_KEYBOARD_KEY + 1)] = 1;
	} else {
		keys[button + (AUTOMATA_INPUT_LAST_KEYBOARD_KEY + 1)] = 0;
	}
}

static void automataInputMousePositionCallback(GLFWwindow *glfwWindow, double xpos, double ypos) {
	/* register mouse input */
	axes[AUTOMATA_AXIS_MOUSE_X] = xpos;
	axes[AUTOMATA_AXIS_MOUSE_Y] = ypos;
}

static void automataInputGamepadAxisCalback() {
	int gamepad = 0;
	int axis = 0;
	int segment = 0;
	int axesCount = 0;
	float *gamepadAxes = NULL;

	while (gamepad <= AUTOMATA_INPUT_LAST_GAMEPAD) {
		/* get gamepad button segment */
		segment = gamepad * AUTOMATA_INPUT_GAMEPAD_AXES_AMOUNT + AUTOMATA_INPUT_LAST_MOUSE_AXIS + 1;

		/* check gamepad state */
		if (automataInputGetGamepadState(gamepad)) {
			/* get gamepad axes */
			gamepadAxes = glfwGetJoystickAxes(gamepad, &axesCount);

			/* register all axes values */
			while (axis < AUTOMATA_INPUT_GAMEPAD_AXES_AMOUNT) {
				if (axis >= axesCount) {
					/* axis doesn't exist */
					axes[axis + segment] = 0.0;
				} else {
					/* axis exists */
					axes[axis + segment] = gamepadAxes[axis];
				}

				++axis;
			}
		}

		axis = 0;
		++gamepad;
	}
}

static void automataInputGamepadButtonCallback() {
	int gamepad = 0;
	int button = 0;
	int segment = 0;
	int buttonsCount = 0;
	unsigned char *gamepadButtons = NULL;

	while (gamepad <= AUTOMATA_INPUT_LAST_GAMEPAD) {
		/* get gamepad button segment */
		segment = gamepad * AUTOMATA_INPUT_GAMEPAD_BUTTONS_AMOUNT + AUTOMATA_INPUT_LAST_MOUSE_BUTTON + 1;

		/* check gamepad state */
		if (automataInputGetGamepadState(gamepad)) {
			/* get gamepad buttons */
			gamepadButtons = glfwGetJoystickButtons(gamepad, &buttonsCount);

			/* register all button values */			
			while (button < AUTOMATA_INPUT_GAMEPAD_BUTTONS_AMOUNT) {
				if (button >= buttonsCount) {
					/* button doesn't exist */
					keys[button + segment] = 0;
				} else {
					/* button exists */
					keys[button + segment] = gamepadButtons[button];
				}

				++button;
			}
		}

		button = 0;
		++gamepad;
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

void automataInputInit(GLFWwindow *window) {
	if (!window) {
		return;
	}
	
	/* add callbacks to window */
	glfwSetKeyCallback(window, automataInputKeyboardKeyCallback);
	glfwSetScrollCallback(window, AutomataInputMouseScrollCallback);
	glfwSetMouseButtonCallback(window, automataInputMouseButtonCallback);
	glfwSetCursorPosCallback(window, automataInputMousePositionCallback);
	glfwSetJoystickCallback(automataInputGamepadConnectedCallback);
}

void automataInputUpdate() {
	/* call manual callbacks */
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

int automataInputGetGamepadState(AutomataInputGamepad gamepad) {
	if (gamepad < 0 || gamepad >= AUTOMATA_INPUT_GAMEPADS_AMOUNT) {
		return -1;
	}

	/* get gamepad state */
	return gamepads[gamepad];
}

const char* automataInputGetGamepadName(AutomataInputGamepad gamepad) {
	if (gamepad < 0 || gamepad >= AUTOMATA_INPUT_GAMEPADS_AMOUNT) {
		return NULL;
	}

	/* get gamepad name */
	return glfwGetJoystickName(gamepad);
}