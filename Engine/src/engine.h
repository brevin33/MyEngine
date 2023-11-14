#pragma once

#include "window.h"
#include "vulkanAPI.h"

namespace myEngine {

class engine
{
public:

public:
	engine();
	~engine();
	void run(int width, int heigth);
private:
	vulkanAPI mGrapicsAPI;
	Window mWindow;

private:
	void mainLoop();

};

}