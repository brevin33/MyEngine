#pragma once
#include "definitions.h"
#include <GLFW/glfw3.h>

namespace myEngine {

class Window
{
public:
	bool pFramebufferResized = false;
	int pWidth;
	int pHeight;
public:
	Window();
	~Window();
	GLFWwindow* getGLFWWindow();
	void create(int width, int height);
	bool shouldClose();
private:
	GLFWwindow* mGLFWWindow;

};
}