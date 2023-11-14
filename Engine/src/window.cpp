#include "window.h"

namespace myEngine {


class Window;

Window::Window() {
}

Window::~Window()
{
    glfwDestroyWindow(mGLFWWindow);
    glfwTerminate();
}

GLFWwindow* Window::getGLFWWindow()
{
    return mGLFWWindow;
}


static void framebufferResizeCallback(GLFWwindow* w, int width, int height) {
    auto app = reinterpret_cast<Window*>(glfwGetWindowUserPointer(w));
    app->pFramebufferResized = true;
    app->pWidth = width;
    app->pHeight = height;
}

void Window::create(int width, int height)
{
    pWidth = width;
    pHeight = height;
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    mGLFWWindow = glfwCreateWindow(width, height, "Vulkan", nullptr, nullptr);
    glfwSetWindowUserPointer(mGLFWWindow, this);
    glfwSetFramebufferSizeCallback(mGLFWWindow, framebufferResizeCallback);
}

bool Window::shouldClose()
{
    return glfwWindowShouldClose(mGLFWWindow);
}

}