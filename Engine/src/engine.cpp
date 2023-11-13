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
	setupGraphicsAPI();
	mainLoop();
}

void engine::mainLoop()
{
	while (!mWindow.shouldClose()) {
		glfwPollEvents();
	}
}

void engine::setupGraphicsAPI()
{
	vulkanAPI v;
	v.setup();
	mGrapicsAPI = v;
}


}