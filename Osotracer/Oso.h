#pragma once
#include <optional>
#include <memory_resource>
#include "glm/glm.hpp"
#include "Material.h"
// base file for different standard datatypes
constexpr float EPS_F = 1e-6f;

using Allocator = std::pmr::polymorphic_allocator<std::byte>;

struct Ray
{
	glm::vec3 origin;
	glm::vec3 direction;
};

// vertices
struct Vertex
{
	glm::vec3 position;
};

struct pnVertex : Vertex
{
	glm::vec3 normal;
};

struct pntVertex : Vertex
{
	glm::vec3 normal;
	glm::vec2 texCoord;
};

struct pnctVertex : Vertex
{
	glm::vec3 normal;
	glm::vec3 color;
	glm::vec2 texCoord;
};

template <typename V>
struct Triangle
{
	static_assert(std::is_base_of<Vertex, V>::value, "Template type must be derived from Vertex");
	V v0;
	V v1;
	V v2;

	glm::vec3 centroid() const
	{
		return (v0.position + v1.position + v2.position) / 3.0f;
	}

	glm::vec3 normal() const
	{
		return glm::cross(v1.position - v0.position, v2.position - v0.position);
	}

	glm::vec3 max() const
	{
		return glm::max(v0.position, glm::max(v1.position, v2.position));
	}

	glm::vec3 min() const
	{
		return glm::min(v0.position, glm::min(v1.position, v2.position));
	}
};

struct pntTriangle : Triangle<pntVertex>
{
	glm::vec3 normal(glm::vec2 uv) const
	{
		return glm::normalize((1.0f - uv.x - uv.y) * v0.normal + uv.x * v1.normal + uv.y * v2.normal);
	}
};

struct HitInfo
{
	float t = std::numeric_limits<float>::max(); // distance to the hit point
	glm::vec3 point; // point of the impact
	glm::vec3 normal; // normal of the impact
	std::shared_ptr<Material> material; // material of the impact
};

/**
 * @brief Möller-Trumbore intersection algorithm
 * @param ray
 * @param invD
 * @param t
 * @param tMax
 * @param triangle
 * @return
*/
std::optional<HitInfo> intersectMT(const Ray& ray, const glm::vec3 invD, float& t, const float tMax, const Triangle<Vertex>& triangle);

/**
 * @brief Woop intersection (2013)
 * @param ray
 * @param invD
 * @param t
 * @param tMax
 * @param triangle
 * @return
*/
std::optional<HitInfo> intersectWoop(const Ray& ray, const glm::vec3 invD, float& t, const float tMax, const Triangle<Vertex>& triangle);

/**
 * @brief Weber intersection (2016)
 * @param ray
 * @param invD
 * @param t
 * @param tMax
 * @param triangle
 * @return
*/
std::optional<HitInfo> intersectWeber(const Ray& ray, const glm::vec3 invD, float& t, const float tMax, const Triangle<Vertex>& triangle);


struct Mesh
{
	std::vector <Vertex> vertices;
	std::vector <uint32_t> indices;
};

