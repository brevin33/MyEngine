#pragma once
#include "../definitions.h"
#include "shader.h"
#include <vector>
#include <array>
#include <GLFW/glfw3.h>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/hash.hpp>
#include <stdexcept>


namespace myEngine{

struct ColorAndTexureVertex {
    glm::vec3 pos;
    glm::vec3 color;
    glm::vec2 texCoord;

    bool operator==(const ColorAndTexureVertex& other) const {
        return pos == other.pos && color == other.color && texCoord == other.texCoord;
    }

    VkVertexInputBindingDescription getBindingDescription() {
        VkVertexInputBindingDescription bindingDescription{};
        bindingDescription.binding = 0;
        bindingDescription.stride = sizeof(ColorAndTexureVertex);
        bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

        return bindingDescription;
    }

    std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions() {
        std::vector<VkVertexInputAttributeDescription> attributeDescriptions;
        attributeDescriptions.resize(3);

        attributeDescriptions[0].binding = 0;
        attributeDescriptions[0].location = 0;
        attributeDescriptions[0].format = VK_FORMAT_R32G32B32_SFLOAT;
        attributeDescriptions[0].offset = offsetof(ColorAndTexureVertex, pos);

        attributeDescriptions[1].binding = 0;
        attributeDescriptions[1].location = 1;
        attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
        attributeDescriptions[1].offset = offsetof(ColorAndTexureVertex, color);

        attributeDescriptions[2].binding = 0;
        attributeDescriptions[2].location = 2;
        attributeDescriptions[2].format = VK_FORMAT_R32G32_SFLOAT;
        attributeDescriptions[2].offset = offsetof(ColorAndTexureVertex, texCoord);

        return attributeDescriptions;
    }

    const size_t hash() const {
        return ((std::hash<glm::vec3>()(pos) ^
            (std::hash<glm::vec3>()(color) << 1)) >> 1) ^
            (std::hash<glm::vec2>()(texCoord) << 1);
    }
};

struct Mesh {
	std::vector<ColorAndTexureVertex> vertices;
    std::vector<uint32_t> indices;

    void loadFromOBJ(std::string filepath, bool colorComponent = false, bool textureComponent = true);
};


struct VKMesh {

    VKMesh() {}

    ~VKMesh() {
        vkDestroyBuffer(*device, indexBuffer, nullptr);
        vkFreeMemory(*device, indexBufferMemory, nullptr);

        vkDestroyBuffer(*device, vertexBuffer, nullptr);
        vkFreeMemory(*device, vertexBufferMemory, nullptr);
    }

    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;
    VkBuffer indexBuffer;
    VkDeviceMemory indexBufferMemory;
    uint32_t indicesSize;
    VkDevice* device;

};


}


namespace std {
    template<> struct std::hash<myEngine::ColorAndTexureVertex> {
        size_t operator()(myEngine::ColorAndTexureVertex const& vertex) const {
            return vertex.hash();
        }
    };
}