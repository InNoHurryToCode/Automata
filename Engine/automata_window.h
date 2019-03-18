#ifndef AUTOMATA_WINDOW_H
#define AUTOMATA_WINDOW_H

#include <glfw/glfw3.h>

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

/* functions */
void automataWindowInit();
void automataWindowCreate(unsigned int width, unsigned int height, const char *title);
void automataWindowClose();
void automataWindowTerminate();
int automataWindowIsAlive();
void automataWindowUpdate();
unsigned int automataWindowGetWidth();
unsigned int automataWindowGetHeight();
const char *automataWindowGetTitle();
AutomataWindowMode automataWindowGetMode();
void automataWindowSetTitle(const char *title);
void automataWindowSetSize(unsigned int width, unsigned int height);
void automataWindowSetMode(AutomataWindowMode mode);

/* callbacks */
void automataWindowCallbackResize(GLFWwindow *glfwWindow, int width, int height);

#endif