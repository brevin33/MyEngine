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
    }
    
    meshID meshid;
    shaderID shaderid;
    std::vector<VkBuffer> uniformBuffers;
    std::vector<VkDeviceMemory> uniformBuffersMemory;
    std::vector<void*> uniformBuffersMapped;
    std::vector<VkDescriptorSet> descriptorSets;
    VkDevice* device;
};