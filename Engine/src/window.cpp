#include "window.h"

namespace myEngine {


class window;

window::window() {
}

window::~window()
{
    glfwDestroyWindow(mGLFWWindow);
    glfwTerminate();
}


static void framebufferResizeCallback(GLFWwindow* w, int width, int height) {
    auto app = reinterpret_cast<window*>(glfwGetWindowUserPointer(w));
    app->pFramebufferResized = true;
    app->pWidth = width;
    app->pHeight = height;
}

void window::create(int width, int height)
{
    pWidth = width;
    pHeight = height;
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    mGLFWWindow = glfwCreateWindow(width, height, "Vulkan", nullptr, nullptr);
    glfwSetWindowUserPointer(mGLFWWindow, this);
    glfwSetFramebufferSizeCallback(mGLFWWindow, framebufferResizeCallback);
}

bool window::shouldClose()
{
    return glfwWindowShouldClose(mGLFWWindow);
}

}