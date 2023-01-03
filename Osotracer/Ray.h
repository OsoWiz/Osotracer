#pragma once
#include <random>
#include "glm/glm.hpp"
struct Ray {
	glm::vec3 origin;
	glm::vec3 direction;
};

namespace RayFunc {
	
	glm::vec3 RandomInUnitSphere() {
		return { 0.f,0.f,0.f };
	}
	
	glm::vec3 randomUnifDist() {
		float x = static_cast<float>(std::rand())/static_cast<float>(RAND_MAX)  - 0.5f;
		float y = static_cast<float>(std::rand())/static_cast<float>(RAND_MAX)  - 0.5f;
		float z = static_cast<float>(std::rand())/static_cast<float>(RAND_MAX)  - 0.5f;
		return { x, y, z };
	}
	
}
