#pragma once
#include "../definitions.h"
#include <GLFW/glfw3.h>

struct ObjectRenderer
{

    ObjectRenderer(){}

    ~ObjectRenderer() {
        for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
            vkDestroyBuffer(*device, uniformBuffers[i], nullptr);
            vkFreeMemory(*device, uniformBuffersMemory[i], nullptr);
        }

        vkDestroyBuffer(*device, indexBuffer, nullptr);
        vkFreeMemory(*device, indexBufferMemory, nullptr);

        vkDestroyBuffer(*device, vertexBuffer, nullptr);
        vkFreeMemory(*device, vertexBufferMemory, nullptr);

        vkDestroyPipeline(*device, graphicsPipeline, nullptr);
        vkDestroyPipelineLayout(*device, pipelineLayout, nullptr);
    }

    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;
    VkBuffer indexBuffer;
    VkDeviceMemory indexBufferMemory;
    std::vector<VkBuffer> uniformBuffers;
    std::vector<VkDeviceMemory> uniformBuffersMemory;
    std::vector<void*> uniformBuffersMapped;
    VkPipelineLayout pipelineLayout;
    VkPipeline graphicsPipeline;
    std::vector<VkDescriptorSet> descriptorSets;
    uint32_t indicesSize;
    VkDevice* device;
};