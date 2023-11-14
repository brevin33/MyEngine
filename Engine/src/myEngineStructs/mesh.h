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

namespace myEngine{

struct Vertex {
    virtual bool operator==(const Vertex& other) const {}

    virtual VkVertexInputBindingDescription getBindingDescription() {}

    virtual std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions() {}

    virtual const size_t hash() const { }
};

struct Mesh {
	std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;
    VulkanGraphicsShader shader;

    void loadFromOBJ(std::string filepath, bool colorComponent = false, bool textureComponent = true);
};

}

namespace std {
    template<> struct std::hash<myEngine::Vertex> {
        size_t operator()(myEngine::Vertex const& vertex) const {
            return vertex.hash();
        }
    };
}