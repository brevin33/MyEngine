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
	Mesh Viking_room;
	Viking_room.loadFromOBJ("models/viking_room/viking_room.obj");
	ShaderSPV shader;
	shader.vertShader = "shaders/vert.spv";
	shader.fragShader = "shaders/frag.spv";
	mGrapicsAPI.createObjectRenderer(Viking_room,shader);
	mGrapicsAPI.createObjectRenderer(Viking_room, shader);

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