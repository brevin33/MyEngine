#pragma once
#include "definitions.h"
#include <GLFW/glfw3.h>

namespace myEngine {

class window
{
public:
	bool pFramebufferResized = false;
	int pWidth;
	int pHeight;
public:
	window();
	~window();
	void create(int width, int height);
	bool shouldClose();
private:
	GLFWwindow* mGLFWWindow;

};
}