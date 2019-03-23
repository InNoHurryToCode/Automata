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
void automataWindowCreate(int width, int height, const char *title);
void automataWindowClose();
void automataWindowTerminate();
int automataWindowIsAlive();
void automataWindowUpdate();
void automataWindowSwapBuffers();
unsigned int automataWindowGetWidth();
unsigned int automataWindowGetHeight();
AutomataWindowMode automataWindowGetMode();
void automataWindowSetTitle(const char *title);
void automataWindowSetSize(int width, int height);
void automataWindowSetMode(AutomataWindowMode mode);
GLFWwindow *automataWindowGetWindow();
void automataWindowSetIcon(int width, int height, unsigned char *pixels);
void automataWindowRemoveIcon();

#endif