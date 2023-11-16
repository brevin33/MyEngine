#pragma once
#include "../definitions.h"
#include <GLFW/glfw3.h>
#include <string>
#include <vector>

namespace myEngine {


struct VKShader {
    VKShader() {}

    ~VKShader() {

        vkDestroyPipeline(*device, graphicsPipeline, nullptr);
        vkDestroyPipelineLayout(*device, pipelineLayout, nullptr);
    }

    VkDevice* device;
	VkPipeline graphicsPipeline;
    VkPipelineLayout pipelineLayout;

};


}