#pragma once
#include "window.h"
namespace myEngine {

class graphicsAPI
{
public:
	virtual void setup(Window &w) {}
	virtual void drawFrame() {}
	virtual ~graphicsAPI() {}
};


}