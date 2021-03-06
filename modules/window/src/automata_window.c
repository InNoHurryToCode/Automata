#include <stdlib.h>
#include <glad/glad.h>
#include "../include/automata/automata_window.h"

static GLFWwindow *window = NULL;
static AutomataWindowMode windowMode;

static void automataWindowCallbackResize(GLFWwindow *glfwWindow, int width, int height) {
	if (!window) {
		return;
	}

	/* apply window size to OpenGL context */
	glViewport(0, 0, width, height);
}

void automataWindowInit() {
	/* initialize GLFW */
	glfwInit();

	/* set OpenGL properties */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, AUTOMATA_OPENGL_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, AUTOMATA_OPENGL_MINOR);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

void automataWindowCreate(int width, int height, const char *title) {		
	const GLFWvidmode *videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());

	if (window || !videoMode || width < 0 || width > videoMode->width || height < 0 || height > videoMode->height || !title) {
		return;
	}
	
	/* create window */
	window = glfwCreateWindow(width, height, title, NULL, NULL);

	if (!window) {
		automataWindowTerminate();
		return;
	}

	/* make window context */
	glfwMakeContextCurrent(window);

	/* check if OpenGL context is initialized */
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		automataWindowTerminate();
		return;
	}

	/* set window viewport */
	glViewport(0, 0, width, height);

	/* set window callback */
	glfwSetFramebufferSizeCallback(window, automataWindowCallbackResize);
}

void automataWindowClose() {
	if (!window) {
		return;
	}

	/* close the window */
	glfwSetWindowShouldClose(window, 1);
}

void automataWindowTerminate() {
	/* terminate glfw */
	glfwTerminate();
}

int automataWindowIsAlive() {
	if (!window) {
		return 0;
	}

	/* get if window is active */
	return !glfwWindowShouldClose(window);
}

void automataWindowUpdate() {
	if (!window) {
		return;
	}

	/* call callbacks */
	glfwPollEvents();
}

void automataWindowSwapBuffers() {
	if (!window) {
		return;
	}

	/* swap buffers */
	glfwSwapBuffers(window);
}

int automataWindowGetWidth() {
	int width = 0;
	int height = 0;
	
	if (!window) {
		return 0;
	}
	
	/* get window width */
	glfwGetWindowSize(window, &width, &height);

	return width;
}

int automataWindowGetHeight() {
	int width = 0;
	int height = 0;

	if (!window) {
		return 0;
	}

	/* get window width */
	glfwGetWindowSize(window, &width, &height);

	return height;
}

AutomataWindowMode automataWindowGetMode() {
	if (!window) {
		return AUTOMATA_WINDOW_MODE_UNKNOWN;
	}
	
	return windowMode;
}

void automataWindowSetTitle(const char *title) {
	if (!window || !title) {
		return;
	}
	
	/* set window title */
	glfwSetWindowTitle(window, title);
}

void automataWindowSetSize(int width, int height) {
	const GLFWvidmode *videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	
	if (!window || !videoMode || width < 0 || width > videoMode->width || height < 0 || height > videoMode->height) {
		return;
	}

	/* apply window size to window */
	glfwSetWindowSize(window, width, height);
}

void automataWindowSetMode(AutomataWindowMode mode) {
	/* get monitor data */
	GLFWmonitor *monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode *videoMode = glfwGetVideoMode(monitor);

	if (!window || mode == windowMode || mode == AUTOMATA_WINDOW_MODE_UNKNOWN) {
		return;
	}

	/* set window mode */	
	switch (mode) {
	case AUTOMATA_WINDOW_MODE_WINDOWED:
		glfwSetWindowMonitor(window, NULL, 0, 0, automataWindowGetWidth(), automataWindowGetHeight(), GLFW_DONT_CARE);
		break;

	case AUTOMATA_WINDOW_MODE_FULLSCREEN:
		glfwSetWindowMonitor(window, monitor, 0, 0, automataWindowGetWidth(), automataWindowGetHeight(), GLFW_DONT_CARE);
		break;

	case AUTOMATA_WINDOW_MODE_BORDERLESS:
		glfwSetWindowMonitor(window, monitor, 0, 0, videoMode->width, videoMode->height, videoMode->refreshRate);
		break;

	default:
		/* window mode doesn't exist */
		break;
	}

	windowMode = mode;
}

GLFWwindow *automataWindowGetWindow() {
	return window;
}

void automataWindowSetIcon(int width, int height, unsigned char *pixels) {
	if (width < 0|| height < 0 || !pixels) {
		return;
	}

	/* get image */
	GLFWimage image[1] = { { 0 } };
	image[0].width = width;
	image[0].height = height;
	image[0].pixels = pixels;

	/* set the window icon */
	glfwSetWindowIcon(window, 1, image);
}

void automataWindowRemoveIcon() {
	/* reset icon to OS default */
	glfwSetWindowIcon(window, 0, NULL);
}