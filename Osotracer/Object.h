#pragma once
#include "Ray.h"
#include "Colors.h"

/**
* @brief Material of an object
* @param ambient Ambient color of the material
* @param diffuse Diffuse color of the material
* @param specular Specular color of the material
* @param shininess Shininess of the material
*/
struct Material {
		floatColor ambient;
		floatColor diffuse;
		floatColor specular;
		float shininess;
	};

/**
* Interface for all objects in the scene
*/
class Object
{
public:
	virtual bool intersect(const Ray& ray, float& t) = 0;
	virtual Material getMaterial() = 0;
};

class Sphere : public Object
{
public:
	Sphere(glm::vec3 pos, float radius, Material material);
	bool intersect(const Ray& ray, float& t) override;
	Material getMaterial() override;
	
private:
	glm::vec3 pos;
	float radius;
	Material material;
};

class Plane : public Object
{
public:
	Plane(glm::vec3 pos, glm::vec3 normal, Material material);
	bool intersect(const Ray& ray, float& t) override;
	Material getMaterial() override;
	
private:
	glm::vec3 pos;
	glm::vec3 normal;
	Material material;
};
