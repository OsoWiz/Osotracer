#pragma once
#include "Ray.h"
#include "Material.h"
/**
* Interface for all objects in the scene
*/
class Object
{
public:
	virtual bool intersect(const Ray& ray, HitInfo& hit) = 0;
	//virtual Material getMaterial() = 0;
};

class Sphere : public Object
{
public:
	Sphere(glm::vec3 pos, float radius, std::shared_ptr<Material> material);
	bool intersect(const Ray& ray, HitInfo& hit) override;
	
private:
	glm::vec3 pos;
	float radius;
	std::shared_ptr<Material> material;
};

class Plane : public Object
{
public:
	Plane(glm::vec3 pos, glm::vec3 normal, std::shared_ptr<Material> material);
	bool intersect(const Ray& ray, HitInfo& hit) override;
	
private:
	glm::vec3 pos;
	glm::vec3 normal;
	std::shared_ptr<Material> material;
};
