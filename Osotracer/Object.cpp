#include "Object.h"

Sphere::Sphere(glm::vec3 pos, float radius, std::shared_ptr<Material> material)
	:Object(pos, material), radius(radius)
{}

bool Sphere::intersect(const Ray& ray, float& t)
{
	return HitInfo();
}

bool Sphere::intersectT(const Ray& ray, float& t, const float tMax)
{
	glm::vec3 toPos = pos - ray.origin;
	float dirDot = glm::dot(toPos, ray.direction);
	if (dirDot < 0) // sphere is behind the ray
		return false;
	float sphereSquare = glm::dot(toPos, toPos) - dirDot * dirDot;
	if (sphereSquare > radius * radius)
		return false;
	float diff = sqrt(radius * radius - sphereSquare);
	float t1 = dirDot + diff;
	t = t1;
	return t1 < tMax;
}

Plane::Plane(glm::vec3 pos, glm::vec3 normal, std::shared_ptr<Material> material)
	:Object(pos, material), normal(normal)
{
}

HitInfo Plane::intersect(const Ray& ray, const glm::vec3 invD, float& t, const float tMax)
{
	return HitInfo();
}

bool Plane::intersectT(const Ray& ray, float& t, const float tMax)
{
	glm::vec3 posDiff = pos - ray.origin;
	// Ray misses if the dot product between the ray direction and the normal is > 0, or if the ray origin is under the plane
	// this may cause issues, if the camera is far far away from the plane origin
	if (0 < glm::dot(ray.direction, normal) || 0 < glm::dot(posDiff, normal))
		return false;

	t = glm::dot(posDiff, normal) / glm::dot(ray.direction, normal);

	return true;
}

AABB::AABB(glm::vec3 min, glm::vec3 max)
	:min(min), max(max)
{
}

bool AABB::intersectT(const Ray& ray, float& t, const float tMax)
{
	float tmin = (min.x - ray.origin.x) / ray.direction.x;
	float tmax = (max.x - ray.origin.x) / ray.direction.x;

	if (tmin > tmax)
		std::swap(tmin, tmax);

	float tymin = (min.y - ray.origin.y) / ray.direction.y;
	float tymax = (max.y - ray.origin.y) / ray.direction.y;

	if (tymin > tymax)
		std::swap(tymin, tymax);

	if ((tmin > tymax) || (tymin > tmax))
		return false;

	if (tymin > tmin)
		tmin = tymin;

	if (tymax < tmax)
		tmax = tymax;

	float tzmin = (min.z - ray.origin.z) / ray.direction.z;
	float tzmax = (max.z - ray.origin.z) / ray.direction.z;

	if (tzmin > tzmax)
		std::swap(tzmin, tzmax);

	if ((tmin > tzmax) || (tzmin > tmax))
		return false;

	if (tzmin > tmin)
		tmin = tzmin;

	if (tzmax < tmax)
		tmax = tzmax;

	t = tmin;

	return true;
}
