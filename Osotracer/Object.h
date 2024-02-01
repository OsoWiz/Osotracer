#pragma once
#include "Oso.h"
#include "Material.h"
constexpr float T_MISS = FLT_MAX;

/**
 * @brief Shape is something that can be intersected, but does not necessarily have to be visible
 */
class Shape
{
public:
	/**
	 * @brief Intersection test for a ray and an object
	 * @param ray to test
	 * @param tMax that limits the maximum distance of the intersection
	 * @return boolean indicating if the ray intersects the object
	 */
	virtual bool intersectT(const Ray& ray, float& t, const float tMax = T_MISS) = 0;
	/**
	 * @brief Returns vertices of the shape in line strip formation
	 * @return the vertices of the shape
	*/
	const std::vector<glm::vec3>& geWireFrameRepresentation() const { return wireFrameRepresentation; }

	std::vector<glm::vec3> wireFrameRepresentation;
};

/**
* Interface for visible objects in the scene
*/
class Object
{
public:

	Object(glm::vec3 pos, std::shared_ptr<Material> material) : pos(pos), material(material) {}
	/**
	 * @brief Intersects a ray with the object and returns the hit information
	 * @param ray to test
	 * @param invD is the inverse direction of the ray
	 * @param t to fill
	 * @param tMax that limits the maximum distance of the intersection
	 * @return HitInfo containing the information about the intersection
	*/
	virtual HitInfo intersect(const Ray& ray, const glm::vec3 invD, float& t, const float tMax = T_MISS) = 0;

protected: // every object has a position and a material
	std::shared_ptr<Material> material;
	glm::vec3 pos;
};

class Sphere : public Object, public Shape
{
public:
	/**
	 * @brief Constructor for a sphere
	 * @param pos of the sphere
	 * @param radius of the sphere
	 * @param material of the sphere
	*/
	Sphere(glm::vec3 pos, float radius, std::shared_ptr<Material> material);
	bool intersect(const Ray& ray, float& t) override;

private:
	float radius;
};

class Plane : public Object, public Shape
{
public:
	Plane(glm::vec3 pos, glm::vec3 normal, std::shared_ptr<Material> material);
	bool intersect(const Ray& ray, float& t) override;

private:
	glm::vec3 normal;
};

#pragma region BoundingVolumes

struct AABB : public Shape
{
	AABB(glm::vec3 min, glm::vec3 max);
	bool intersectT(const Ray& ray, float& t, const float tMax = T_MISS) override;
	float area() const { return 2 * (max.x - min.x) * (max.y - min.y) + 2 * (max.x - min.x) * (max.z - min.z) + 2 * (max.y - min.y) * (max.z - min.z); }
	glm::vec3 min;
	glm::vec3 max;
};

#pragma endregion