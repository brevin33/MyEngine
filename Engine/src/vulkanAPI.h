#pragma once
#include "definitions.h"
#include "window.h"
#include <string>
#include <optional>
#include <vector>
#include <array>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/hash.hpp>
#include "myEngineStructs/mesh.h"
#include "myEngineStructs/shader.h"
#include "myEngineStructs/objectRenderer.h"
#include <memory>

namespace myEngine {

struct UniformBufferObject {
    alignas(16) glm::mat4 model;
    alignas(16) glm::mat4 view;
    alignas(16) glm::mat4 proj;
};

}

namespace myEngine {


struct SwapChainSupportDetails {
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};


struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete() {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};



class vulkanAPI
{
public:
    ~vulkanAPI();
    void setup(Window &window);

    uint32_t createObjectRenderer( Mesh &mesh, ShaderSPV &shader);

    void drawFrame();

private:
    Window* window;
    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
    VkSurfaceKHR surface;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device;
    VkQueue graphicsQueue;
    VkQueue presentQueue;
    VkRenderPass renderPass;
    VkDescriptorSetLayout descriptorSetLayout;
    VkCommandPool commandPool;



    uint32_t mipLevels;
    VkImage textureImage;
    VkDeviceMemory textureImageMemory;
    VkImageView textureImageView;
    VkSampler textureSampler;

    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    std::vector<VkImageView> swapChainImageViews;
    std::vector<VkFramebuffer> swapChainFramebuffers;

    VkImage colorImage;
    VkDeviceMemory colorImageMemory;
    VkImageView colorImageView;

    VkImage depthImage;
    VkDeviceMemory depthImageMemory;
    VkImageView depthImageView;

    VkSampleCountFlagBits msaaSamples = VK_SAMPLE_COUNT_1_BIT;


    VkDescriptorPool descriptorPool;

    std::vector<VkCommandBuffer> commandBuffers;

    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    std::vector<VkFence> inFlightFences;
    uint32_t currentFrame = 0;


    std::vector<std::unique_ptr<ObjectRenderer>> objectsToRender;

private:
    void createInstance();
    void setupDebugMessenger();
    void createSurface();
    void pickPhysicalDevice();
    void createLogicalDevice();
    void createSwapChain();
    void createImageViews();
    void createRenderPass();
    void createDescriptorSetLayout();
    void createCommandPool();
    void createColorResources();
    void createDepthResources();
    void createFramebuffers();
    void createTextureImage();
    void createTextureImageView();
    void createTextureSampler();
    void createDescriptorPool();
    void createCommandBuffers();
    void createSyncObjects();


    void recreateSwapChain();
    void updateUniformBuffer(uint32_t currentImage, std::vector<void*>& uniformBuffersMapped);
    void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

    void createVertexBuffer(const std::vector<ColorAndTexureVertex>& vertices, VkBuffer& vertexBuffer, VkDeviceMemory& vertexBufferMemory);
    void createIndexBuffer(const std::vector<uint32_t>& indices, VkBuffer& indexBuffer, VkDeviceMemory& indexBufferMemory);
    void createGraphicsPipeline(VulkanGraphicsShader& shader, VkPipelineLayout& pipelineLayout, VkPipeline& graphicsPipeline, ColorAndTexureVertex& vertex);
    void createUniformBuffers(std::vector<VkBuffer>& uniformBuffers, std::vector<VkDeviceMemory>& uniformBuffersMemory, std::vector<void*>& uniformBuffersMapped);
    void createDescriptorSets(std::vector<VkDescriptorSet>& descriptorSets, std::vector<VkBuffer> &uniformBuffers);



    VkCommandBuffer beginSingleTimeCommands();
    void endSingleTimeCommands(VkCommandBuffer commandBuffer);
    void generateMipmaps(VkImage image, VkFormat imageFormat, int32_t texWidth, int32_t texHeight, uint32_t mipLevels);
    void transitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout, uint32_t mipLevels = 1);
    void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
    void copyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);
    void createImage(uint32_t width, uint32_t height, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory, uint32_t mipLevels, VkSampleCountFlagBits numSamples);
    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
    static std::vector<char> readFile(const std::string& filename);
    VkImageView createImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlags, uint32_t mipLevels = 1);
    VkFormat findSupportedFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features);

    void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
    void cleanupSwapChain();
    VkShaderModule createShaderModule(const std::vector<char>& code);


    bool hasStencilComponent(VkFormat format);
    VkFormat findDepthFormat();
    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
    bool checkDeviceExtensionSupport(VkPhysicalDevice device);
    VkSampleCountFlagBits getMaxUsableSampleCount();
    bool isDeviceSuitable(VkPhysicalDevice device);
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
    bool checkValidationLayerSupport();
    std::vector<const char*> getRequiredExtensions();
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);

};

}