#pragma once
#include "../definitions.h"
#include <GLFW/glfw3.h>
#include <string>
#include <vector>

namespace myEngine {

class VulkanGraphicsShader
{
public:
    VkPipelineShaderStageCreateInfo shaderStages[2];
public:
    ~VulkanGraphicsShader();
	void loadSPV(std::string vertexShader, std::string fragShader, VkDevice* device);

private:
    VkShaderModule vertShaderModule;
    VkShaderModule fragShaderModule;
    VkDevice* device;
private:
    VkShaderModule createShaderModule(const std::vector<char>& code);
    std::vector<char> readFile(const std::string& filename);

};


}