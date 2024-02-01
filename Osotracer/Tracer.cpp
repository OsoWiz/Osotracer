#include "Tracer.h"
#include <algorithm>

// helper functions
inline bool axisComparison(glm::vec3 first, glm::vec3 second, Axis axis)
{
	return first[axis] < second[axis];
}
/**
 * @brief Returns the longest axis of the given dimensions
 * @param dimensions of the bounding box
 * @return longest axis
*/
inline Axis longestAxis(glm::vec3 dimensions)
{
	Axis axis = Axis::X;
	if (dimensions[axis] < dimensions.y) // is there a faster way?
		axis = Axis::Y;
	if (dimensions[axis] < dimensions.z)
		axis = Axis::Z;
	return axis;
}

inline float sahCost(const AABB& box, size_t count)
{
	return box.area() * count;
}

template <typename VertexType>
inline size_t splitMedian(const std::vector<Triangle<VertexType>>& triangles, uint32_t* indices, const size_t start, const size_t end)
{
	// find longest axis
	glm::vec3 dimensions = triangles[start].getBoundingBox().getDimensions();
	Axis axis = longestAxis(dimensions);

	// partition triangles by axis
	size_t median = std::partition(indices + start, indices + end, [&](uint32_t a, uint32_t b)
		{
			return axisComparison(triangles[a].centroid(), triangles[b].centroid(), axis);
		});


	return median;
}

template <typename VertexType>
inline size_t splitSAH(const std::vector<Triangle<VertexType>>& triangles, uint32_t* indices, const size_t start, const size_t end)
{
	// sample potential split points
	return 0;
}

template <typename VertexType>
void recursiveSplitRoutine(const std::vector<Triangle<VertexType>>& triangles, SplitFunc<VertexType> splitFunction, std::unique_ptr<BVHNode> node, const uint32_t leafObjectCount, uint32_t* indices, const size_t start, const size_t end)
{
	// Bounding box is always calculated for that node.
	glm::vec3 min = glm::vec3(std::numeric_limits<float>::max());
	glm::vec3 max = glm::vec3(std::numeric_limits<float>::min());
	for (size_t i = start; i < end; i++)
	{
		min = glm::min(min, triangles[i].min());
		max = glm::max(max, triangles[i].max());
	}
	node->aabb = AABB(min, max);

	if (end - start < leafObjectCount)
		return;

	// split
	size_t split = splitFunction(triangles, indices, start, end);
	node->left = std::make_unique<BVHNode>();
	node->right = std::make_unique<BVHNode>();
	recursiveSplitRoutine(triangles, splitFunction, node->left, leafObjectCount, indices, start, split);
	recursiveSplitRoutine(triangles, splitFunction, node->right, leafObjectCount, indices, split, end);

}

// tracer functionality
template<typename VertexType>
void BVHTreeRayTracer<VertexType>::buildBVH(const std::vector<Triangle<VertexType>>& triangles, BVHBuildMethod buildMethod, const uint32_t leafObjectCount)
{
	m_root = std::make_unique<BVHNode>();
	switch (buildMethod)
	{
		case SAH:
		{
			recursiveSplitRoutine(triangles, splitSAH, leafObjectCount, m_indices, 0, triangles.size());
			break;
		}
		case Median:
		{
			recursiveSplitRoutine(triangles, splitMedian, leafObjectCount, m_indices, 0, triangles.size());
			break;
		}
		default:
			break;
	}
	// copy the triangles according to sorted indices
	for (size_t i = 0; i < triangles.size(); i++)
	{
		m_triangles.push_back(triangles[m_indices[i]]);
	}
}

template<typename VertexType>
std::optional<HitInfo> BVHTreeRayTracer<VertexType>::TraceRay(const Ray& ray, const float tMax)
{
	return std::optional<HitInfo>();
}
