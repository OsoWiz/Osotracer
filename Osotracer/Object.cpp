#include "Object.h"

Sphere::Sphere(glm::vec3 pos, float radius, std::shared_ptr<Material> material)
	:pos(pos), radius(radius), material(material)
{}

bool Sphere::intersect(const Ray& ray, float& t)
{
	glm::vec3 L = pos - ray.origin;
	float tca = glm::dot(L, ray.direction);
	if (tca < 0)
		return false;
	float d2 = glm::dot(L, L) - tca * tca;
	if (d2 > radius * radius)
		return false;
	float thc = sqrt(radius * radius - d2);
	t = tca - thc;
	float t1 = tca + thc;
	if (t < 0)
		t = t1;
	
	return true;
}

Plane::Plane(glm::vec3 pos, glm::vec3 normal, std::shared_ptr<Material> material)
	:pos(pos), normal(normal), material(material)
{
}

bool Plane::intersect(const Ray& ray, float& t)
{
	// Ray misses if the dot product between the ray direction and the normal is > 0
	if (glm::dot(ray.direction, normal) > 0)
		return false;
	
	// ray hits at this point if it passes the test above
	t = glm::dot(pos - ray.origin, normal) / glm::dot(ray.direction, normal);
	
	return true;
}

