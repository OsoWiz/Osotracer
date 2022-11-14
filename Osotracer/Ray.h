#pragma once
#include <limits>
#include "glm/glm.hpp"
struct Ray {
	float t = std::numeric_limits<float>::max();
	glm::vec3 origin;
	glm::vec3 direction;
};

