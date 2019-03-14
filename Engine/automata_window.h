#ifndef AUTOMATA_WINDOW_H
#define AUTOMATA_WINDOW_H

#include <glfw/glfw3.h>

/* types */
typedef struct AutomataWindow AutomataWindow;

struct AutomataWindow {
	GLFWwindow *window;
	unsigned int width;
	unsigned int height;
	const char *title;
};

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
void automataWindowSetTitle(const char *title);
void automataWindowSetSize(unsigned int width, unsigned int height);

/* callbacks */
void automataWindowCallbackResize(GLFWwindow* glfwWindow, int width, int height);

#endif