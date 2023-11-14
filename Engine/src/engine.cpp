#include "engine.h"
#include "vulkanAPI.h"
namespace myEngine {


engine::engine()
{
}

engine::~engine()
{
}

void engine::run(int width, int height)
{
	mWindow.create(width, height);
	mGrapicsAPI.setup(mWindow);
	mainLoop();
}

void engine::mainLoop()
{
	while (!mWindow.shouldClose()) {
		glfwPollEvents();
		mGrapicsAPI.drawFrame();
	}
}



}