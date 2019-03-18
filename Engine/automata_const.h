#ifndef AUTOMATA_CONST_H
#define AUTOMATA_CONST_H

#include <GLFW/glfw3.h>

/* engine version */
#define AUTOMATA_VERSION_MAJOR 1
#define AUTOMATA_VERSION_MINOR 0 
#define AUTOMATA_VERSION_FIX 0
#define AUTOMATA_VERSION_TYPE 'A'

/* OpenGL version */
#define AUTOMATA_OPENGL_MAJOR 3
#define AUTOMATA_OPENGL_MINOR 3

/* data structures */
typedef enum AutomataWindowMode {
	AUTOMATA_WINDOW_MODE_UNKNOWN = -1,
	AUTOMATA_WINDOW_MODE_WINDOWED,
	AUTOMATA_WINDOW_MODE_FULLSCREEN,
	AUTOMATA_WINDOW_MODE_BORDERLESS
} AutomataWindowMode;

#endif