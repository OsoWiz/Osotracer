#include "Oso.h"

std::optional<HitInfo> intersectMT(const Ray& ray, const glm::vec3 invD, float& t, const float tMax, const Triangle<Vertex>& triangle)
{
	glm::vec3 p0 = triangle.v0.position;
	glm::vec3 p1 = triangle.v1.position;
	glm::vec3 p2 = triangle.v2.position;
	glm::vec3 e1 = p1 - p0;
	glm::vec3 e2 = p2 - p0;
	glm::vec3 rxe2 = glm::cross(ray.direction, e2);
	float det = glm::dot(e1, rxe2);

	if (std::abs(det) < EPS_F)
		return std::nullopt;

	float invDet = 1.0f / det;
	glm::vec3 v0 = ray.origin - p0;
	float u = glm::dot(v0, rxe2) * invDet;

	if (u < 0.0f || u > 1.0f)
		return std::nullopt;

	glm::vec3 sxe1 = glm::cross(v0, e1);
	float v = glm::dot(ray.direction, sxe1) * invDet;

	if (v < 0.0f || u + v > 1.0f)
		return std::nullopt;

	float tempT = glm::dot(e2, sxe1) * invDet;

	if (tempT < 0.0f || tempT > tMax)
		return std::nullopt;

	t = tempT;
	return HitInfo{ tempT, ray.origin + t * ray.direction, triangle.normal(), nullptr };
}
