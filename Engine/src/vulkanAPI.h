#pragma once
#include "graphicsAPI.h"
#include "definitions.h"
#include <vector>
#include <GLFW/glfw3.h>
namespace myEngine {

class vulkanAPI :
    public graphicsAPI
{
public:
    ~vulkanAPI();
    void setup();

private:
    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
private:
    void createInstance();
    void setupDebugMessenger();
    bool checkValidationLayerSupport();
    std::vector<const char*> getRequiredExtensions();
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);

};

}