#pragma once
#include <limits>
#include <memory>
#include "Ray.h"
#include "Colors.h"

struct ScatterInfo {
	Ray* scatteredRays;
	int numScatteredRays;
	Ray shadow;
	float attenuation = 0.f;
};

/**
* @brief Material interface. Materials describe how light reflects off them
*/
class Material {	
public:
	// Calculates a scattered ray to out and attenuation to hitInfo
	virtual bool Scatter(const Ray in, glm::vec3 normal, ScatterInfo& scatterInfo) const = 0;
};

struct HitInfo
{
	float t = std::numeric_limits<float>::max(); // distance to the hit point
	glm::vec3 normal; // normal of the impact
	std::shared_ptr<Material> material; // material of the impact
};

class PhongMaterial: Material {
public:
	PhongMaterial(float specular, float diffuse, float ambient, float shininess);
	
	bool Scatter(const Ray& in, glm::vec3 normal, ScatterInfo& scatterInfo) const;
private:
	float matSpecular, matDiffuse, matAmbient, matShininess;
};

class GlassMaterial : Material {
public:
	GlassMaterial(float refractiveIndex);

	bool Scatter(const Ray& in, glm::vec3 normal, ScatterInfo& scatterInfo) const;
private:
	float refractiveIndex;
};

class Metal : Material {
public:
	Metal(float shininess, float fuzziness);

	bool Scatter(const Ray& in, glm::vec3 normal, ScatterInfo& scatterInfo) const;
private:
	float shininess, fuzziness;
};