#include <stdlib.h>
#include <glad/glad.h>
#include "automata_const.h"
#include "automata_window.h"

static AutomataWindow *window = NULL;

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
	/* allocate window memory */
	window = malloc(sizeof(AutomataWindow *));

	if (!window) {
		return;
	}

	/* create window */
	window->width = width;
	window->height = height;
	window->title = title;
	window->window = glfwCreateWindow(window->width, window->height, window->title, NULL, NULL);

	if (!window->window) {
		automataWindowTerminate();
		return;
	}

	/* make window context */
	glfwMakeContextCurrent(window->window);

	/* check if OpenGL context is initialized */
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		automataWindowTerminate();
		return;
	}

	/* set window viewport */
	glViewport(0, 0, window->width, window->height);

	/* set window callback */
	glfwSetFramebufferSizeCallback(window->window, automataWindowCallbackResize);
}

void automataWindowTerminate() {
	/* terminate glfw */
	glfwTerminate();
}

int automataWindowIsAlive() {
	/* get if window is active */
	return !glfwWindowShouldClose(window->window);
}

void automataWindowUpdate() {
	/* swap buffer and call callbacks */
	glfwSwapBuffers(window->window);
	glfwPollEvents();
}

unsigned int automataWindowGetWidth() {
	/* get window width */
	return window->width;
}

unsigned int automataWindowGetHeight() {
	/* get window height */
	return window->height;
}

const char *automataWindowGetTitle() {
	/* get window title */
	return window->title;
}

void automataWindowSetTitle(const char *title) {
	/* set window title */
	window->title = title;

	glfwSetWindowTitle(window->window, title);
}

void automataWindowSetSize(unsigned int width, unsigned int height) {
	if (!window) {
		return;
	}

	/* set window size */
	window->width = width;
	window->height = height;

	/* apply window size to window */
	glfwSetWindowSize(window->window, window->width, window->height);
}

void automataWindowCallbackResize(GLFWwindow* glfwWindow, int width, int height) {
	if (!window) {
		return;
	}

	/* set window size */
	window->width = (unsigned int)width;
	window->height = (unsigned int)height;

	/* apply window size to OpenGL context */
	glViewport(0, 0, width, height);
}