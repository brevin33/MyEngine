#pragma once
#include "../../definitions.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <inttypes.h>

namespace myEngine{
struct transform {
	entityID id;
	glm::mat4x4 model;
};

}