#pragma once

#include "Camera.h"
#include "Scene.h"



struct TraceOptions {
	int width; // width of the trace
	int height; // height of the trace
	int maxDepth;
};

namespace Tracer {
	// renders image to the given buffer
	void render(const Camera& camera, const Scene& scene, const TraceOptions& options, unsigned char* buffer);

	// return the color of a singular traced ray
	Colors::color traceRay(const Scene& scene, const Ray& ray, int depth);

	// return the color of a singular traced ray recursively
	Colors::color traceRayRecursive(const Scene& scene, const Ray& ray, int depth);
	
}
