#ifndef AUTOMATA_CONST_H
#define AUTOMATA_CONST_H

/* engine version */
#define AUTOMATA_VERSION_TYPE 'A'
#define AUTOMATA_VERSION_MAJOR 1
#define AUTOMATA_VERSION_MINOR 0 
#define AUTOMATA_VERSION_FIX 0

/* OpenGL version */
#define AUTOMATA_OPENGL_MAJOR 3
#define AUTOMATA_OPENGL_MINOR 3

/* window modes */
typedef enum AutomataWindowModes {
	AUTOMATA_WINDOW_MODE_UNKNOWN = -1,
	AUTOMATA_WINDOW_MODE_WINDOWED,
	AUTOMATA_WINDOW_MODE_FULLSCREEN,
	AUTOMATA_WINDOW_MODE_BORDERLESS
} AutomataWindowModes;

/* input keys amount */
#define AUTOMATA_INPUT_KEYBOARD_KEYS_AMOUNT 348
#define AUTOMATA_INPUT_MOUSE_BUTTONS_AMOUNT 8
#define AUTOMATA_INPUT_KEYS_TOTAL_AMOUNT AUTOMATA_INPUT_KEYBOARD_KEYS_AMOUNT + AUTOMATA_INPUT_MOUSE_BUTTONS_AMOUNT

/* input key values */
typedef enum AutomataInputKeys { 
	AUTOMATA_INPUT_KEY_MOUSE_1 = AUTOMATA_INPUT_KEYBOARD_KEYS_AMOUNT,
	AUTOMATA_INPUT_KEY_MOUSE_2,
	AUTOMATA_INPUT_KEY_MOUSE_3,
	AUTOMATA_INPUT_KEY_MOUSE_4,
	AUTOMATA_INPUT_KEY_MOUSE_5,
	AUTOMATA_INPUT_KEY_MOUSE_6,
	AUTOMATA_INPUT_KEY_MOUSE_7,
	AUTOMATA_INPUT_KEY_MOUSE_8
} AutomataInputKeys;

#endif