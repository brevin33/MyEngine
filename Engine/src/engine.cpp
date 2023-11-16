#include "engine.h"
#include "vulkanAPI.h"
#include <chrono>
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
	Mesh Viking_room;
	Viking_room.loadFromOBJ("models/viking_room/viking_room.obj");
	std::string vertShader = "shaders/vert.spv";
	std::string fragShader = "shaders/frag.spv";
	shaderID sID = mGrapicsAPI.createShader(vertShader, fragShader, Viking_room.vertices[0]);
	meshID mID = mGrapicsAPI.createMesh(Viking_room);
	objectRendererID oID = mGrapicsAPI.createObjectRenderer(sID, mID);

	static auto startTime = std::chrono::high_resolution_clock::now();

	auto currentTime = std::chrono::high_resolution_clock::now();
	float time = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - startTime).count();

	UniformBufferObject ubo{};
	ubo.model = glm::rotate(glm::mat4(1.0f), time * glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	ubo.view = glm::lookAt(glm::vec3(2.0f, 2.0f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	ubo.proj = glm::perspective(glm::radians(45.0f), mGrapicsAPI.swapChainExtent.width / (float)mGrapicsAPI.swapChainExtent.height, 0.1f, 10.0f);
	ubo.proj[1][1] *= -1;

	mGrapicsAPI.setUBOAll(oID, ubo);

	while (!mWindow.shouldClose()) {
		glfwPollEvents();

		mGrapicsAPI.drawFrame();
	}
}




}