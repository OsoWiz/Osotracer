#pragma once

#include "Camera.h"
#include "Scene.h"

#include <functional>

/**
 * @brief Split function splits the given triangle list through the indices pointer and returns the split point.
 * @tparam V Vertex type supplied to the triangle list.
*/
template <typename V>
using SplitFunc = size_t(*)(const std::vector<Triangle<V>>&, uint32_t*, const size_t, const size_t...);

enum BVHBuildMethod : uint32_t
{
	SAH = 0,
	Median = 1
};

enum Axis : uint32_t
{
	X = 0,
	Y = 1,
	Z = 2
};

struct BVHNode
{
	AABB aabb;
	std::unique_ptr<BVHNode> left;
	std::unique_ptr<BVHNode> right;

	uint32_t start; // first index of the vertices or objects
	uint32_t end; // last index + 1 of the vertices or objects (e.g for whole container the size of the container)
};

template <typename V>
SplitFunc<V> splitSAH;
template <typename V>
SplitFunc<V> splitMedian;



struct TraceOptions
{
	int width; // width of the trace
	int height; // height of the trace
	int maxDepth;
};

/**
 * @brief Basic raytracer interface a Ray tracer should provide.
*/
template <typename VertexType>
class RayTracer
{
	static_assert(std::is_base_of<Vertex, VertexType>::value, "VertexType must be derived from Vertex");

public:

	/**
	 * @brief Builds the BVH for the given triangles
	 * @param triangles
	 * @param buildMethod
	 * @param leafObjectCount is the maximum number of objects in a leaf node. If the number of objects is less than this value, the node is a leaf node.
	*/
	void buildBVH(const std::vector<Triangle<VertexType>>& triangles, BVHBuildMethod buildMethod, const uint32_t leafObjectCount) = 0;

	/**
	 * @brief Traces a ray through the scene using the built bvh. This function must be called only after the bvh has been built.
	 * @param ray to trace
	 * @param tMax is the maximum distance the ray can travel and hits can be considered.
	 * @return
	*/
	std::optional<HitInfo> TraceRay(const Ray& ray, const float tMax) = 0;

protected:
	// Every raytracer has a list of triangles and indices to go with it.
	std::vector <Triangle<VertexType>> m_triangles;
	std::vector<uint32_t> m_indices; // indices can be sorted instead of the triangles

};

template <typename VertexType>
class BVHTreeRayTracer : public RayTracer<VertexType>
{
public:
	/**
	 * @brief Builds the BVH for the given triangles
	 * @param triangles
	 * @param buildMethod
	*/
	void buildBVH(const std::vector<Triangle<VertexType>>& triangles, BVHBuildMethod buildMethod, const uint32_t leafObjectCount) override;

	/**
	 * @brief Traces a ray through the scene using the built bvh. This function must be called only after the bvh has been built.
	 * @param ray to trace
	 * @param tMax is the maximum distance the ray can travel and hits can be considered.
	 * @return
	*/
	std::optional<HitInfo> TraceRay(const Ray& ray, const float tMax) override;

private:
	std::unique_ptr<BVHNode> m_root;
};
