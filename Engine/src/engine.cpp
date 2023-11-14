#include "engine.h"
#include "vulkanAPI.h"
namespace myEngine {


engine::engine()
{
}

engine::~engine()
{
	delete mGrapicsAPI;
}

void engine::run(int width, int height)
{
	mWindow.create(width, height);
	setupGraphicsAPI();
	mainLoop();
}

void engine::mainLoop()
{
	while (!mWindow.shouldClose()) {
		glfwPollEvents();
		mGrapicsAPI->drawFrame();
	}
}

void engine::setupGraphicsAPI()
{
	mGrapicsAPI = new vulkanAPI;
	mGrapicsAPI->setup(mWindow);
}


}