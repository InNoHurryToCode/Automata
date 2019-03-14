#ifndef AUTOMATA_INPUT_H
#define AUTOMATA_INPUT_H

#include <glfw/glfw3.h>

/* functions */
int automataInputGetKey(int key);
int automataInputGetAnyKey();
double automataInputGetMouseX();
double automataInputGetMouseY();

/* callbacks */
void automataInputKeyboardKeyCallback(GLFWwindow* glfwWindow, int key, int scancode, int action, int mods);
void automataInputMouseButtonCallback(GLFWwindow* glfwWindow, int button, int action, int mods);
void automataInputMousePositionCallback(GLFWwindow* glfwWindow, double xpos, double ypos);

#endif