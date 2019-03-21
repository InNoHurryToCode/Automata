#ifndef AUTOMATA_INPUT_H
#define AUTOMATA_INPUT_H

#include <glfw/glfw3.h>

/* constant */
#define AUTOMATA_INPUT_LAST_KEYBOARD_KEY AUTOMATA_KEY_MENU	
#define AUTOMATA_INPUT_LAST_MOUSE_BUTTON AUTOMATA_KEY_MOUSE_8
#define AUTOMATA_INPUT_LAST_MOUSE_AXIS AUTOMATA_AXIS_MOUSE_SCROLL
#define AUTOMATA_INPUT_LAST_GAMEPAD AUTOMATA_GAMEPAD_16

#define AUTOMATA_INPUT_MOUSE_BUTTONS_AMOUNT 8
#define AUTOMATA_INPUT_MOUSE_AXES_AMOUNT 3
#define AUTOMATA_INPUT_GAMEPAD_BUTTONS_AMOUNT 20
#define AUTOMATA_INPUT_GAMEPAD_AXES_AMOUNT 4

#define AUTOMATA_INPUT_KEYS_AMOUNT AUTOMATA_KEY_GAMEPAD_16_20 + 1
#define AUTOMATA_INPUT_AXES_AMOUNT AUTOMATA_AXIS_GAMEPAD_16_RTHUMB_Y + 1
#define AUTOMATA_INPUT_GAMEPADS_AMOUNT AUTOMATA_INPUT_LAST_GAMEPAD + 1

/* data structures */
typedef enum AutomataInputKey {
	/* keypad */
	AUTOMATA_KEY_KP_0			= GLFW_KEY_KP_0,
	AUTOMATA_KEY_KP_1			= GLFW_KEY_KP_1,
	AUTOMATA_KEY_KP_2			= GLFW_KEY_KP_2,
	AUTOMATA_KEY_KP_3			= GLFW_KEY_KP_3,
	AUTOMATA_KEY_KP_4			= GLFW_KEY_KP_4,
	AUTOMATA_KEY_KP_5			= GLFW_KEY_KP_5,
	AUTOMATA_KEY_KP_6			= GLFW_KEY_KP_6,
	AUTOMATA_KEY_KP_7			= GLFW_KEY_KP_7,
	AUTOMATA_KEY_KP_8			= GLFW_KEY_KP_8,
	AUTOMATA_KEY_KP_9			= GLFW_KEY_KP_9,
	AUTOMATA_KEY_KP_DECIMAL		= GLFW_KEY_KP_DECIMAL,
	AUTOMATA_KEY_KP_DIVIDE		= GLFW_KEY_KP_DIVIDE,
	AUTOMATA_KEY_KP_MULTIPLY	= GLFW_KEY_KP_MULTIPLY,
	AUTOMATA_KEY_KP_SUBTRACT	= GLFW_KEY_KP_SUBTRACT,
	AUTOMATA_KEY_KP_ADD			= GLFW_KEY_KP_ADD,
	AUTOMATA_KEY_KP_ENTER		= GLFW_KEY_KP_ENTER,
	AUTOMATA_KEY_KP_EQUAL		= GLFW_KEY_KP_EQUAL,

	AUTOMATA_KEY_UNKNOWN = GLFW_KEY_UNKNOWN,
	
	/* numbers */
	AUTOMATA_KEY_0 = GLFW_KEY_0,
	AUTOMATA_KEY_1 = GLFW_KEY_1,
	AUTOMATA_KEY_2 = GLFW_KEY_2,
	AUTOMATA_KEY_3 = GLFW_KEY_3,
	AUTOMATA_KEY_4 = GLFW_KEY_4,
	AUTOMATA_KEY_5 = GLFW_KEY_5,
	AUTOMATA_KEY_6 = GLFW_KEY_6,
	AUTOMATA_KEY_7 = GLFW_KEY_7,
	AUTOMATA_KEY_8 = GLFW_KEY_8,
	AUTOMATA_KEY_9 = GLFW_KEY_9,
	
	/* function keys */
	AUTOMATA_KEY_F1 = GLFW_KEY_F1,
	AUTOMATA_KEY_F2 = GLFW_KEY_F2,
	AUTOMATA_KEY_F3 = GLFW_KEY_F3,
	AUTOMATA_KEY_F4 = GLFW_KEY_F4,
	AUTOMATA_KEY_F5 = GLFW_KEY_F5,
	AUTOMATA_KEY_F6 = GLFW_KEY_F6,
	AUTOMATA_KEY_F7 = GLFW_KEY_F7,
	AUTOMATA_KEY_F8 = GLFW_KEY_F8,
	AUTOMATA_KEY_F9 = GLFW_KEY_F9,
	AUTOMATA_KEY_F10 = GLFW_KEY_F10,
	AUTOMATA_KEY_F11 = GLFW_KEY_F11,
	AUTOMATA_KEY_F12 = GLFW_KEY_F12,

	/* letters */
	AUTOMATA_KEY_A = GLFW_KEY_A,
	AUTOMATA_KEY_B = GLFW_KEY_B,
	AUTOMATA_KEY_C = GLFW_KEY_C,
	AUTOMATA_KEY_D = GLFW_KEY_D,
	AUTOMATA_KEY_E = GLFW_KEY_E,
	AUTOMATA_KEY_F = GLFW_KEY_F,
	AUTOMATA_KEY_G = GLFW_KEY_G,
	AUTOMATA_KEY_H = GLFW_KEY_H,
	AUTOMATA_KEY_I = GLFW_KEY_I,
	AUTOMATA_KEY_J = GLFW_KEY_J,
	AUTOMATA_KEY_K = GLFW_KEY_K,
	AUTOMATA_KEY_L = GLFW_KEY_L,
	AUTOMATA_KEY_M = GLFW_KEY_M,
	AUTOMATA_KEY_N = GLFW_KEY_N,
	AUTOMATA_KEY_O = GLFW_KEY_O,
	AUTOMATA_KEY_P = GLFW_KEY_P,
	AUTOMATA_KEY_Q = GLFW_KEY_Q,
	AUTOMATA_KEY_R = GLFW_KEY_R,
	AUTOMATA_KEY_S = GLFW_KEY_S,
	AUTOMATA_KEY_T = GLFW_KEY_T,
	AUTOMATA_KEY_U = GLFW_KEY_U,
	AUTOMATA_KEY_V = GLFW_KEY_V,
	AUTOMATA_KEY_W = GLFW_KEY_W,
	AUTOMATA_KEY_X = GLFW_KEY_X,
	AUTOMATA_KEY_Y = GLFW_KEY_Y,
	AUTOMATA_KEY_Z = GLFW_KEY_Z,

	/* special keys */
	AUTOMATA_KEY_UP				= GLFW_KEY_UP,
	AUTOMATA_KEY_DOWN			= GLFW_KEY_DOWN,
	AUTOMATA_KEY_LEFT			= GLFW_KEY_LEFT,
	AUTOMATA_KEY_RIGHT			= GLFW_KEY_RIGHT,
	AUTOMATA_KEY_SPACE			= GLFW_KEY_SPACE,
	AUTOMATA_KEY_ENTER			= GLFW_KEY_ENTER,
	AUTOMATA_KEY_ESC			= GLFW_KEY_ESCAPE,
	AUTOMATA_KEY_TAB			= GLFW_KEY_TAB,
	AUTOMATA_KEY_LCTRL			= GLFW_KEY_LEFT_CONTROL,
	AUTOMATA_KEY_RCTRL			= GLFW_KEY_RIGHT_CONTROL,
	AUTOMATA_KEY_LSHIFT			= GLFW_KEY_LEFT_SHIFT,
	AUTOMATA_KEY_RSHIFT			= GLFW_KEY_RIGHT_SHIFT,
	AUTOMATA_KEY_LALT			= GLFW_KEY_LEFT_ALT,
	AUTOMATA_KEY_RALT			= GLFW_KEY_RIGHT_ALT,
	AUTOMATA_KEY_LBRACKET		= GLFW_KEY_LEFT_BRACKET,
	AUTOMATA_KEY_RBRACKET		= GLFW_KEY_RIGHT_BRACKET,
	AUTOMATA_KEY_LSUPER			= GLFW_KEY_LEFT_SUPER,
	AUTOMATA_KEY_RSUPER			= GLFW_KEY_RIGHT_SUPER,
	AUTOMATA_KEY_QOUTE			= GLFW_KEY_APOSTROPHE,
	AUTOMATA_KEY_COMMA			= GLFW_KEY_COMMA,
	AUTOMATA_KEY_MINUS			= GLFW_KEY_MINUS,
	AUTOMATA_KEY_PERIOD			= GLFW_KEY_PERIOD,
	AUTOMATA_KEY_SLASH			= GLFW_KEY_SLASH,
	AUTOMATA_KEY_SEMICOLON		= GLFW_KEY_SEMICOLON,
	AUTOMATA_KEY_EQUAL			= GLFW_KEY_EQUAL,
	AUTOMATA_KEY_BACSLASH		= GLFW_KEY_BACKSLASH,
	AUTOMATA_KEY_GRAVE_ACCENT	= GLFW_KEY_GRAVE_ACCENT,
	AUTOMATA_KEY_WORLD1			= GLFW_KEY_WORLD_1,
	AUTOMATA_KEY_WORLD2			= GLFW_KEY_WORLD_2,
	AUTOMATA_KEY_BACKSPACE		= GLFW_KEY_BACKSPACE,
	AUTOMATA_KEY_INSERT			= GLFW_KEY_INSERT,
	AUTOMATA_KEY_DELETE			= GLFW_KEY_DELETE,
	AUTOMATA_KEY_PAGEUP			= GLFW_KEY_PAGE_UP,
	AUTOMATA_KEY_PAGEDOWN		= GLFW_KEY_PAGE_DOWN,
	AUTOMATA_KEY_HOME			= GLFW_KEY_HOME,
	AUTOMATA_KEY_END			= GLFW_KEY_END,
	AUTOMATA_KEY_CAPSLOCK		= GLFW_KEY_CAPS_LOCK,
	AUTOMATA_KEY_SCROLLLOCK		= GLFW_KEY_SCROLL_LOCK,
	AUTOMATA_KEY_NUMLOCK		= GLFW_KEY_NUM_LOCK,
	AUTOMATA_KEY_PRINTSCREEN	= GLFW_KEY_PRINT_SCREEN,
	AUTOMATA_KEY_PAUSE			= GLFW_KEY_PAUSE,
	AUTOMATA_KEY_MENU			= GLFW_KEY_MENU,

	/* mouse buttons */
	AUTOMATA_KEY_MOUSE_LEFT,
	AUTOMATA_KEY_MOUSE_RIGHT,
	AUTOMATA_KEY_MOUSE_MIDDLE,
	AUTOMATA_KEY_MOUSE_4,
	AUTOMATA_KEY_MOUSE_5,
	AUTOMATA_KEY_MOUSE_6,
	AUTOMATA_KEY_MOUSE_7,
	AUTOMATA_KEY_MOUSE_8,

	/* gamepad 1 */
	AUTOMATA_KEY_GAMEPAD_1_1,
	AUTOMATA_KEY_GAMEPAD_1_2,
	AUTOMATA_KEY_GAMEPAD_1_3,
	AUTOMATA_KEY_GAMEPAD_1_4,
	AUTOMATA_KEY_GAMEPAD_1_5,
	AUTOMATA_KEY_GAMEPAD_1_6,
	AUTOMATA_KEY_GAMEPAD_1_7,
	AUTOMATA_KEY_GAMEPAD_1_8,
	AUTOMATA_KEY_GAMEPAD_1_9,
	AUTOMATA_KEY_GAMEPAD_1_10,
	AUTOMATA_KEY_GAMEPAD_1_11,
	AUTOMATA_KEY_GAMEPAD_1_12,
	AUTOMATA_KEY_GAMEPAD_1_13,
	AUTOMATA_KEY_GAMEPAD_1_14,
	AUTOMATA_KEY_GAMEPAD_1_15,
	AUTOMATA_KEY_GAMEPAD_1_16,
	AUTOMATA_KEY_GAMEPAD_1_17,
	AUTOMATA_KEY_GAMEPAD_1_18,
	AUTOMATA_KEY_GAMEPAD_1_19,
	AUTOMATA_KEY_GAMEPAD_1_20,

	/* gamepad 2 */
	AUTOMATA_KEY_GAMEPAD_2_1,
	AUTOMATA_KEY_GAMEPAD_2_2,
	AUTOMATA_KEY_GAMEPAD_2_3,
	AUTOMATA_KEY_GAMEPAD_2_4,
	AUTOMATA_KEY_GAMEPAD_2_5,
	AUTOMATA_KEY_GAMEPAD_2_6,
	AUTOMATA_KEY_GAMEPAD_2_7,
	AUTOMATA_KEY_GAMEPAD_2_8,
	AUTOMATA_KEY_GAMEPAD_2_9,
	AUTOMATA_KEY_GAMEPAD_2_10,
	AUTOMATA_KEY_GAMEPAD_2_11,
	AUTOMATA_KEY_GAMEPAD_2_12,
	AUTOMATA_KEY_GAMEPAD_2_13,
	AUTOMATA_KEY_GAMEPAD_2_14,
	AUTOMATA_KEY_GAMEPAD_2_15,
	AUTOMATA_KEY_GAMEPAD_2_16,
	AUTOMATA_KEY_GAMEPAD_2_17,
	AUTOMATA_KEY_GAMEPAD_2_18,
	AUTOMATA_KEY_GAMEPAD_2_19,
	AUTOMATA_KEY_GAMEPAD_2_20,

	/* gamepad 3 */
	AUTOMATA_KEY_GAMEPAD_3_1,
	AUTOMATA_KEY_GAMEPAD_3_2,
	AUTOMATA_KEY_GAMEPAD_3_3,
	AUTOMATA_KEY_GAMEPAD_3_4,
	AUTOMATA_KEY_GAMEPAD_3_5,
	AUTOMATA_KEY_GAMEPAD_3_6,
	AUTOMATA_KEY_GAMEPAD_3_7,
	AUTOMATA_KEY_GAMEPAD_3_8,
	AUTOMATA_KEY_GAMEPAD_3_9,
	AUTOMATA_KEY_GAMEPAD_3_10,
	AUTOMATA_KEY_GAMEPAD_3_11,
	AUTOMATA_KEY_GAMEPAD_3_12,
	AUTOMATA_KEY_GAMEPAD_3_13,
	AUTOMATA_KEY_GAMEPAD_3_14,
	AUTOMATA_KEY_GAMEPAD_3_15,
	AUTOMATA_KEY_GAMEPAD_3_16,
	AUTOMATA_KEY_GAMEPAD_3_17,
	AUTOMATA_KEY_GAMEPAD_3_18,
	AUTOMATA_KEY_GAMEPAD_3_19,
	AUTOMATA_KEY_GAMEPAD_3_20,

	/* gamepad 4 */
	AUTOMATA_KEY_GAMEPAD_4_1,
	AUTOMATA_KEY_GAMEPAD_4_2,
	AUTOMATA_KEY_GAMEPAD_4_3,
	AUTOMATA_KEY_GAMEPAD_4_4,
	AUTOMATA_KEY_GAMEPAD_4_5,
	AUTOMATA_KEY_GAMEPAD_4_6,
	AUTOMATA_KEY_GAMEPAD_4_7,
	AUTOMATA_KEY_GAMEPAD_4_8,
	AUTOMATA_KEY_GAMEPAD_4_9,
	AUTOMATA_KEY_GAMEPAD_4_10,
	AUTOMATA_KEY_GAMEPAD_4_11,
	AUTOMATA_KEY_GAMEPAD_4_12,
	AUTOMATA_KEY_GAMEPAD_4_13,
	AUTOMATA_KEY_GAMEPAD_4_14,
	AUTOMATA_KEY_GAMEPAD_4_15,
	AUTOMATA_KEY_GAMEPAD_4_16,
	AUTOMATA_KEY_GAMEPAD_4_17,
	AUTOMATA_KEY_GAMEPAD_4_18,
	AUTOMATA_KEY_GAMEPAD_4_19,
	AUTOMATA_KEY_GAMEPAD_4_20,

	/* gamepad 5 */
	AUTOMATA_KEY_GAMEPAD_5_1,
	AUTOMATA_KEY_GAMEPAD_5_2,
	AUTOMATA_KEY_GAMEPAD_5_3,
	AUTOMATA_KEY_GAMEPAD_5_4,
	AUTOMATA_KEY_GAMEPAD_5_5,
	AUTOMATA_KEY_GAMEPAD_5_6,
	AUTOMATA_KEY_GAMEPAD_5_7,
	AUTOMATA_KEY_GAMEPAD_5_8,
	AUTOMATA_KEY_GAMEPAD_5_9,
	AUTOMATA_KEY_GAMEPAD_5_10,
	AUTOMATA_KEY_GAMEPAD_5_11,
	AUTOMATA_KEY_GAMEPAD_5_12,
	AUTOMATA_KEY_GAMEPAD_5_13,
	AUTOMATA_KEY_GAMEPAD_5_14,
	AUTOMATA_KEY_GAMEPAD_5_15,
	AUTOMATA_KEY_GAMEPAD_5_16,
	AUTOMATA_KEY_GAMEPAD_5_17,
	AUTOMATA_KEY_GAMEPAD_5_18,
	AUTOMATA_KEY_GAMEPAD_5_19,
	AUTOMATA_KEY_GAMEPAD_5_20,

	/* gamepad 6 */
	AUTOMATA_KEY_GAMEPAD_6_1,
	AUTOMATA_KEY_GAMEPAD_6_2,
	AUTOMATA_KEY_GAMEPAD_6_3,
	AUTOMATA_KEY_GAMEPAD_6_4,
	AUTOMATA_KEY_GAMEPAD_6_5,
	AUTOMATA_KEY_GAMEPAD_6_6,
	AUTOMATA_KEY_GAMEPAD_6_7,
	AUTOMATA_KEY_GAMEPAD_6_8,
	AUTOMATA_KEY_GAMEPAD_6_9,
	AUTOMATA_KEY_GAMEPAD_6_10,
	AUTOMATA_KEY_GAMEPAD_6_11,
	AUTOMATA_KEY_GAMEPAD_6_12,
	AUTOMATA_KEY_GAMEPAD_6_13,
	AUTOMATA_KEY_GAMEPAD_6_14,
	AUTOMATA_KEY_GAMEPAD_6_15,
	AUTOMATA_KEY_GAMEPAD_6_16,
	AUTOMATA_KEY_GAMEPAD_6_17,
	AUTOMATA_KEY_GAMEPAD_6_18,
	AUTOMATA_KEY_GAMEPAD_6_19,
	AUTOMATA_KEY_GAMEPAD_6_20,

	/* gamepad 7 */
	AUTOMATA_KEY_GAMEPAD_7_1,
	AUTOMATA_KEY_GAMEPAD_7_2,
	AUTOMATA_KEY_GAMEPAD_7_3,
	AUTOMATA_KEY_GAMEPAD_7_4,
	AUTOMATA_KEY_GAMEPAD_7_5,
	AUTOMATA_KEY_GAMEPAD_7_6,
	AUTOMATA_KEY_GAMEPAD_7_7,
	AUTOMATA_KEY_GAMEPAD_7_8,
	AUTOMATA_KEY_GAMEPAD_7_9,
	AUTOMATA_KEY_GAMEPAD_7_10,
	AUTOMATA_KEY_GAMEPAD_7_11,
	AUTOMATA_KEY_GAMEPAD_7_12,
	AUTOMATA_KEY_GAMEPAD_7_13,
	AUTOMATA_KEY_GAMEPAD_7_14,
	AUTOMATA_KEY_GAMEPAD_7_15,
	AUTOMATA_KEY_GAMEPAD_7_16,
	AUTOMATA_KEY_GAMEPAD_7_17,
	AUTOMATA_KEY_GAMEPAD_7_18,
	AUTOMATA_KEY_GAMEPAD_7_19,
	AUTOMATA_KEY_GAMEPAD_7_20,

	/* gamepad 8 */
	AUTOMATA_KEY_GAMEPAD_8_1,
	AUTOMATA_KEY_GAMEPAD_8_2,
	AUTOMATA_KEY_GAMEPAD_8_3,
	AUTOMATA_KEY_GAMEPAD_8_4,
	AUTOMATA_KEY_GAMEPAD_8_5,
	AUTOMATA_KEY_GAMEPAD_8_6,
	AUTOMATA_KEY_GAMEPAD_8_7,
	AUTOMATA_KEY_GAMEPAD_8_8,
	AUTOMATA_KEY_GAMEPAD_8_9,
	AUTOMATA_KEY_GAMEPAD_8_10,
	AUTOMATA_KEY_GAMEPAD_8_11,
	AUTOMATA_KEY_GAMEPAD_8_12,
	AUTOMATA_KEY_GAMEPAD_8_13,
	AUTOMATA_KEY_GAMEPAD_8_14,
	AUTOMATA_KEY_GAMEPAD_8_15,
	AUTOMATA_KEY_GAMEPAD_8_16,
	AUTOMATA_KEY_GAMEPAD_8_17,
	AUTOMATA_KEY_GAMEPAD_8_18,
	AUTOMATA_KEY_GAMEPAD_8_19,
	AUTOMATA_KEY_GAMEPAD_8_20,

	/* gamepad 9 */
	AUTOMATA_KEY_GAMEPAD_9_1,
	AUTOMATA_KEY_GAMEPAD_9_2,
	AUTOMATA_KEY_GAMEPAD_9_3,
	AUTOMATA_KEY_GAMEPAD_9_4,
	AUTOMATA_KEY_GAMEPAD_9_5,
	AUTOMATA_KEY_GAMEPAD_9_6,
	AUTOMATA_KEY_GAMEPAD_9_7,
	AUTOMATA_KEY_GAMEPAD_9_8,
	AUTOMATA_KEY_GAMEPAD_9_9,
	AUTOMATA_KEY_GAMEPAD_9_10,
	AUTOMATA_KEY_GAMEPAD_9_11,
	AUTOMATA_KEY_GAMEPAD_9_12,
	AUTOMATA_KEY_GAMEPAD_9_13,
	AUTOMATA_KEY_GAMEPAD_9_14,
	AUTOMATA_KEY_GAMEPAD_9_15,
	AUTOMATA_KEY_GAMEPAD_9_16,
	AUTOMATA_KEY_GAMEPAD_9_17,
	AUTOMATA_KEY_GAMEPAD_9_18,
	AUTOMATA_KEY_GAMEPAD_9_19,
	AUTOMATA_KEY_GAMEPAD_9_20,

	/* gamepad 10 */
	AUTOMATA_KEY_GAMEPAD_10_1,
	AUTOMATA_KEY_GAMEPAD_10_2,
	AUTOMATA_KEY_GAMEPAD_10_3,
	AUTOMATA_KEY_GAMEPAD_10_4,
	AUTOMATA_KEY_GAMEPAD_10_5,
	AUTOMATA_KEY_GAMEPAD_10_6,
	AUTOMATA_KEY_GAMEPAD_10_7,
	AUTOMATA_KEY_GAMEPAD_10_8,
	AUTOMATA_KEY_GAMEPAD_10_9,
	AUTOMATA_KEY_GAMEPAD_10_10,
	AUTOMATA_KEY_GAMEPAD_10_11,
	AUTOMATA_KEY_GAMEPAD_10_12,
	AUTOMATA_KEY_GAMEPAD_10_13,
	AUTOMATA_KEY_GAMEPAD_10_14,
	AUTOMATA_KEY_GAMEPAD_10_15,
	AUTOMATA_KEY_GAMEPAD_10_16,
	AUTOMATA_KEY_GAMEPAD_10_17,
	AUTOMATA_KEY_GAMEPAD_10_18,
	AUTOMATA_KEY_GAMEPAD_10_19,
	AUTOMATA_KEY_GAMEPAD_10_20,

	/* gamepad 11 */
	AUTOMATA_KEY_GAMEPAD_11_1,
	AUTOMATA_KEY_GAMEPAD_11_2,
	AUTOMATA_KEY_GAMEPAD_11_3,
	AUTOMATA_KEY_GAMEPAD_11_4,
	AUTOMATA_KEY_GAMEPAD_11_5,
	AUTOMATA_KEY_GAMEPAD_11_6,
	AUTOMATA_KEY_GAMEPAD_11_7,
	AUTOMATA_KEY_GAMEPAD_11_8,
	AUTOMATA_KEY_GAMEPAD_11_9,
	AUTOMATA_KEY_GAMEPAD_11_10,
	AUTOMATA_KEY_GAMEPAD_11_11,
	AUTOMATA_KEY_GAMEPAD_11_12,
	AUTOMATA_KEY_GAMEPAD_11_13,
	AUTOMATA_KEY_GAMEPAD_11_14,
	AUTOMATA_KEY_GAMEPAD_11_15,
	AUTOMATA_KEY_GAMEPAD_11_16,
	AUTOMATA_KEY_GAMEPAD_11_17,
	AUTOMATA_KEY_GAMEPAD_11_18,
	AUTOMATA_KEY_GAMEPAD_11_19,
	AUTOMATA_KEY_GAMEPAD_11_20,

	/* gamepad 12 */
	AUTOMATA_KEY_GAMEPAD_12_1,
	AUTOMATA_KEY_GAMEPAD_12_2,
	AUTOMATA_KEY_GAMEPAD_12_3,
	AUTOMATA_KEY_GAMEPAD_12_4,
	AUTOMATA_KEY_GAMEPAD_12_5,
	AUTOMATA_KEY_GAMEPAD_12_6,
	AUTOMATA_KEY_GAMEPAD_12_7,
	AUTOMATA_KEY_GAMEPAD_12_8,
	AUTOMATA_KEY_GAMEPAD_12_9,
	AUTOMATA_KEY_GAMEPAD_12_10,
	AUTOMATA_KEY_GAMEPAD_12_11,
	AUTOMATA_KEY_GAMEPAD_12_12,
	AUTOMATA_KEY_GAMEPAD_12_13,
	AUTOMATA_KEY_GAMEPAD_12_14,
	AUTOMATA_KEY_GAMEPAD_12_15,
	AUTOMATA_KEY_GAMEPAD_12_16,
	AUTOMATA_KEY_GAMEPAD_12_17,
	AUTOMATA_KEY_GAMEPAD_12_18,
	AUTOMATA_KEY_GAMEPAD_12_19,
	AUTOMATA_KEY_GAMEPAD_12_20,

	/* gamepad 13 */
	AUTOMATA_KEY_GAMEPAD_13_1,
	AUTOMATA_KEY_GAMEPAD_13_2,
	AUTOMATA_KEY_GAMEPAD_13_3,
	AUTOMATA_KEY_GAMEPAD_13_4,
	AUTOMATA_KEY_GAMEPAD_13_5,
	AUTOMATA_KEY_GAMEPAD_13_6,
	AUTOMATA_KEY_GAMEPAD_13_7,
	AUTOMATA_KEY_GAMEPAD_13_8,
	AUTOMATA_KEY_GAMEPAD_13_9,
	AUTOMATA_KEY_GAMEPAD_13_10,
	AUTOMATA_KEY_GAMEPAD_13_11,
	AUTOMATA_KEY_GAMEPAD_13_12,
	AUTOMATA_KEY_GAMEPAD_13_13,
	AUTOMATA_KEY_GAMEPAD_13_14,
	AUTOMATA_KEY_GAMEPAD_13_15,
	AUTOMATA_KEY_GAMEPAD_13_16,
	AUTOMATA_KEY_GAMEPAD_13_17,
	AUTOMATA_KEY_GAMEPAD_13_18,
	AUTOMATA_KEY_GAMEPAD_13_19,
	AUTOMATA_KEY_GAMEPAD_13_20,

	/* gamepad 14 */
	AUTOMATA_KEY_GAMEPAD_14_1,
	AUTOMATA_KEY_GAMEPAD_14_2,
	AUTOMATA_KEY_GAMEPAD_14_3,
	AUTOMATA_KEY_GAMEPAD_14_4,
	AUTOMATA_KEY_GAMEPAD_14_5,
	AUTOMATA_KEY_GAMEPAD_14_6,
	AUTOMATA_KEY_GAMEPAD_14_7,
	AUTOMATA_KEY_GAMEPAD_14_8,
	AUTOMATA_KEY_GAMEPAD_14_9,
	AUTOMATA_KEY_GAMEPAD_14_10,
	AUTOMATA_KEY_GAMEPAD_14_11,
	AUTOMATA_KEY_GAMEPAD_14_12,
	AUTOMATA_KEY_GAMEPAD_14_13,
	AUTOMATA_KEY_GAMEPAD_14_14,
	AUTOMATA_KEY_GAMEPAD_14_15,
	AUTOMATA_KEY_GAMEPAD_14_16,
	AUTOMATA_KEY_GAMEPAD_14_17,
	AUTOMATA_KEY_GAMEPAD_14_18,
	AUTOMATA_KEY_GAMEPAD_14_19,
	AUTOMATA_KEY_GAMEPAD_14_20,

	/* gamepad 15 */
	AUTOMATA_KEY_GAMEPAD_15_1,
	AUTOMATA_KEY_GAMEPAD_15_2,
	AUTOMATA_KEY_GAMEPAD_15_3,
	AUTOMATA_KEY_GAMEPAD_15_4,
	AUTOMATA_KEY_GAMEPAD_15_5,
	AUTOMATA_KEY_GAMEPAD_15_6,
	AUTOMATA_KEY_GAMEPAD_15_7,
	AUTOMATA_KEY_GAMEPAD_15_8,
	AUTOMATA_KEY_GAMEPAD_15_9,
	AUTOMATA_KEY_GAMEPAD_15_10,
	AUTOMATA_KEY_GAMEPAD_15_11,
	AUTOMATA_KEY_GAMEPAD_15_12,
	AUTOMATA_KEY_GAMEPAD_15_13,
	AUTOMATA_KEY_GAMEPAD_15_14,
	AUTOMATA_KEY_GAMEPAD_15_15,
	AUTOMATA_KEY_GAMEPAD_15_16,
	AUTOMATA_KEY_GAMEPAD_15_17,
	AUTOMATA_KEY_GAMEPAD_15_18,
	AUTOMATA_KEY_GAMEPAD_15_19,
	AUTOMATA_KEY_GAMEPAD_15_20,

	/* gamepad 16 */
	AUTOMATA_KEY_GAMEPAD_16_1,
	AUTOMATA_KEY_GAMEPAD_16_2,
	AUTOMATA_KEY_GAMEPAD_16_3,
	AUTOMATA_KEY_GAMEPAD_16_4,
	AUTOMATA_KEY_GAMEPAD_16_5,
	AUTOMATA_KEY_GAMEPAD_16_6,
	AUTOMATA_KEY_GAMEPAD_16_7,
	AUTOMATA_KEY_GAMEPAD_16_8,
	AUTOMATA_KEY_GAMEPAD_16_9,
	AUTOMATA_KEY_GAMEPAD_16_10,
	AUTOMATA_KEY_GAMEPAD_16_11,
	AUTOMATA_KEY_GAMEPAD_16_12,
	AUTOMATA_KEY_GAMEPAD_16_13,
	AUTOMATA_KEY_GAMEPAD_16_14,
	AUTOMATA_KEY_GAMEPAD_16_15,
	AUTOMATA_KEY_GAMEPAD_16_16,
	AUTOMATA_KEY_GAMEPAD_16_17,
	AUTOMATA_KEY_GAMEPAD_16_18,
	AUTOMATA_KEY_GAMEPAD_16_19,
	AUTOMATA_KEY_GAMEPAD_16_20
} AutomataInputKey;

typedef enum AutomataInputAxis {
	/* mouse */
	AUTOMATA_AXIS_MOUSE_X = 0,
	AUTOMATA_AXIS_MOUSE_Y,
	AUTOMATA_AXIS_MOUSE_SCROLL,
	
	/* gamepad 1 */
	AUTOMATA_AXIS_GAMEPAD_1_LTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_1_LTHUMB_Y,
	AUTOMATA_AXIS_GAMEPAD_1_RTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_1_RTHUMB_Y,
	
	/* gamepad 2 */
	AUTOMATA_AXIS_GAMEPAD_2_LTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_2_LTHUMB_Y,
	AUTOMATA_AXIS_GAMEPAD_2_RTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_2_RTHUMB_Y,

	/* gamepad 3 */
	AUTOMATA_AXIS_GAMEPAD_3_LTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_3_LTHUMB_Y,
	AUTOMATA_AXIS_GAMEPAD_3_RTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_3_RTHUMB_Y,
	
	/* gamepad 4 */
	AUTOMATA_AXIS_GAMEPAD_4_LTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_4_LTHUMB_Y,
	AUTOMATA_AXIS_GAMEPAD_4_RTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_4_RTHUMB_Y,
	
	/* gamepad 5 */
	AUTOMATA_AXIS_GAMEPAD_5_LTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_5_LTHUMB_Y,
	AUTOMATA_AXIS_GAMEPAD_5_RTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_5_RTHUMB_Y,

	/* gamepad 6 */
	AUTOMATA_AXIS_GAMEPAD_6_LTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_6_LTHUMB_Y,
	AUTOMATA_AXIS_GAMEPAD_6_RTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_6_RTHUMB_Y,

	/* gamepad 7 */
	AUTOMATA_AXIS_GAMEPAD_7_LTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_7_LTHUMB_Y,
	AUTOMATA_AXIS_GAMEPAD_7_RTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_7_RTHUMB_Y,

	/* gamepad 8 */
	AUTOMATA_AXIS_GAMEPAD_8_LTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_8_LTHUMB_Y,
	AUTOMATA_AXIS_GAMEPAD_8_RTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_8_RTHUMB_Y,

	/* gamepad 9 */
	AUTOMATA_AXIS_GAMEPAD_9_LTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_9_LTHUMB_Y,
	AUTOMATA_AXIS_GAMEPAD_9_RTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_9_RTHUMB_Y,

	/* gamepad 10 */
	AUTOMATA_AXIS_GAMEPAD_10_LTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_10_LTHUMB_Y,
	AUTOMATA_AXIS_GAMEPAD_10_RTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_10_RTHUMB_Y,

	/* gamepad 11 */
	AUTOMATA_AXIS_GAMEPAD_11_LTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_11_LTHUMB_Y,
	AUTOMATA_AXIS_GAMEPAD_11_RTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_11_RTHUMB_Y,
	
	/* gamepad 12 */
	AUTOMATA_AXIS_GAMEPAD_12_LTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_12_LTHUMB_Y,
	AUTOMATA_AXIS_GAMEPAD_12_RTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_12_RTHUMB_Y,
	
	/* gamepad 13 */
	AUTOMATA_AXIS_GAMEPAD_13_LTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_13_LTHUMB_Y,
	AUTOMATA_AXIS_GAMEPAD_13_RTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_13_RTHUMB_Y,
	
	/* gamepad 14 */
	AUTOMATA_AXIS_GAMEPAD_14_LTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_14_LTHUMB_Y,
	AUTOMATA_AXIS_GAMEPAD_14_RTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_14_RTHUMB_Y,
	
	/* gamepad 15 */
	AUTOMATA_AXIS_GAMEPAD_15_LTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_15_LTHUMB_Y,
	AUTOMATA_AXIS_GAMEPAD_15_RTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_15_RTHUMB_Y,

	/* gamepad 16 */
	AUTOMATA_AXIS_GAMEPAD_16_LTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_16_LTHUMB_Y,
	AUTOMATA_AXIS_GAMEPAD_16_RTHUMB_X,
	AUTOMATA_AXIS_GAMEPAD_16_RTHUMB_Y
} AutomataInputAxis;

typedef enum AutomataInputGamepad {
	AUTOMATA_GAMEPAD_1 = 0,
	AUTOMATA_GAMEPAD_2,
	AUTOMATA_GAMEPAD_3,
	AUTOMATA_GAMEPAD_4,
	AUTOMATA_GAMEPAD_5,
	AUTOMATA_GAMEPAD_6,
	AUTOMATA_GAMEPAD_7,
	AUTOMATA_GAMEPAD_8,
	AUTOMATA_GAMEPAD_9,
	AUTOMATA_GAMEPAD_10,
	AUTOMATA_GAMEPAD_11,
	AUTOMATA_GAMEPAD_12,
	AUTOMATA_GAMEPAD_13,
	AUTOMATA_GAMEPAD_14,
	AUTOMATA_GAMEPAD_15,
	AUTOMATA_GAMEPAD_16
} AutomataInputGamepad;

/* functions */
void automataInputInit(GLFWwindow *window);
void automataInputUpdate();
int automataInputGetKey(AutomataInputKey key);
int automataInputGetAnyKey();
AutomataInputKey automataInputDetectKey();
double automataInputGetAxis(AutomataInputAxis axis);
int automataInputGetGamepadState(AutomataInputGamepad gamepad);
const char* automataInputGetGamepadName(AutomataInputGamepad gamepad);
void automataInputSetCursorVisible(int visible);
void automataInputSetCursorIcon(int width, int height, unsigned char pixels);
void automataInputRemoveCursorIcon();

#endif