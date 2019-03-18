#include <stdlib.h>
#include <glad/glad.h>
#include "automata_input.h"
#include "automata_window.h"

struct AutomataWindow {
	GLFWwindow *window;
	unsigned int width;
	unsigned int height;
	const char *title;
	AutomataWindowMode mode;
} AutomataWindow;

static struct AutomataWindow window = { 0 };

void automataWindowInit() {
	/* initialize GLFW */
	glfwInit();

	/* set OpenGL properties */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, AUTOMATA_OPENGL_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, AUTOMATA_OPENGL_MINOR);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

void automataWindowCreate(unsigned int width, unsigned int height, const char *title) {		
	/* create window */
	window.width = width;
	window.height = height;
	window.title = title;
	window.window = glfwCreateWindow(width, height, title, NULL, NULL);

	if (!window.window) {
		automataWindowTerminate();
		return;
	}

	/* make window context */
	glfwMakeContextCurrent(window.window);

	/* check if OpenGL context is initialized */
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		automataWindowTerminate();
		return;
	}

	/* set window viewport */
	glViewport(0, 0, window.width, window.height);

	/* set window callback */
	glfwSetFramebufferSizeCallback(window.window, automataWindowCallbackResize);
	glfwSetKeyCallback(window.window, automataInputKeyboardKeyCallback);
	glfwSetMouseButtonCallback(window.window, automataInputMouseButtonCallback);
	glfwSetCursorPosCallback(window.window, automataInputMousePositionCallback);
	glfwSetJoystickCallback(automataInputGamepadConnectedCallback);
}

void automataWindowClose() {
	if (!window.window) {
		return;
	}

	/* close the window */
	glfwSetWindowShouldClose(window.window, 1);
}

void automataWindowTerminate() {
	/* terminate glfw */
	glfwTerminate();
}

int automataWindowIsAlive() {
	if (!window.window) {
		return 0;
	}

	/* get if window is active */
	return !glfwWindowShouldClose(window.window);
}

void automataWindowUpdate() {
	if (!window.window) {
		return;
	}

	/* swap buffer and call callbacks */
	glfwSwapBuffers(window.window);
	glfwPollEvents();
}

unsigned int automataWindowGetWidth() {
	if (!window.window) {
		return 0;
	}
	
	/* get window width */
	return window.width;
}

unsigned int automataWindowGetHeight() {
	if (!window.window) {
		return 0;
	}
	
	/* get window height */
	return window.height;
}

const char *automataWindowGetTitle() {
	if (!window.window) {
		return NULL;
	}
	
	/* get window title */
	return window.title;
}

AutomataWindowMode automataWindowGetMode() {
	if (!window.window) {
		return AUTOMATA_WINDOW_MODE_UNKNOWN;
	}
	
	return window.mode;
}

void automataWindowSetTitle(const char *title) {
	if (!window.window) {
		return;
	}
	
	/* set window title */
	window.title = title;

	glfwSetWindowTitle(window.window, title);
}

void automataWindowSetSize(unsigned int width, unsigned int height) {
	if (!window.window) {
		return;
	}

	/* set window size */
	window.width = width;
	window.height = height;

	/* apply window size to window */
	glfwSetWindowSize(window.window, (int)width, (int)height);
}

void automataWindowSetMode(AutomataWindowMode mode) {
	/* get monitor data */
	GLFWmonitor *monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode *videoMode = glfwGetVideoMode(monitor);

	if (!window.window || mode == window.mode) {
		return;
	}

	/* set window mode */
	window.mode = mode;
	
	switch (mode) {
	case AUTOMATA_WINDOW_MODE_WINDOWED:
		glfwSetWindowMonitor(window.window, NULL, 0, 0, window.width, window.height, GLFW_DONT_CARE);
		break;

	case AUTOMATA_WINDOW_MODE_FULLSCREEN:
		glfwSetWindowMonitor(window.window, monitor, 0, 0, window.width, window.height, GLFW_DONT_CARE);
		break;

	case AUTOMATA_WINDOW_MODE_BORDERLESS:
		glfwSetWindowMonitor(window.window, monitor, 0, 0, videoMode->width, videoMode->height, videoMode->refreshRate);
		break;

	default:
		/* window mode doesn't exist */
		window.mode = AUTOMATA_WINDOW_MODE_UNKNOWN;
		return;
	}

	if (window.mode == AUTOMATA_WINDOW_MODE_UNKNOWN) {
		automataWindowTerminate();
		return;
	}
}

void automataWindowCallbackResize(GLFWwindow *glfwWindow, int width, int height) {
	if (!window.window) {
		return;
	}

	/* set window size */
	window.width = (unsigned int)width;
	window.height = (unsigned int)height;

	/* apply window size to OpenGL context */
	glViewport(0, 0, width, height);
}