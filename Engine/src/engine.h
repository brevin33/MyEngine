#pragma once

#include "window.h"
#include "graphicsAPI.h"

namespace myEngine {

class engine
{
public:

public:
	engine();
	~engine();
	void run(int width, int heigth);
private:
	graphicsAPI* mGrapicsAPI;
	Window mWindow;

private:
	void mainLoop();
	void setupGraphicsAPI();

};

}