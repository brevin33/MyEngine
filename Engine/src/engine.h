#pragma once

#include "window.h"
namespace myEngine {



class engine
{
public:

public:
	engine();
	~engine();
	void run(int width, int heigth);
private:
	window mWindow;

private:
	void mainLoop();

};

}