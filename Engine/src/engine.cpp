#include "engine.h"

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

	mainLoop();

}

void engine::mainLoop()
{
	while (!mWindow.shouldClose()) {
		glfwPollEvents();
	}
}


}