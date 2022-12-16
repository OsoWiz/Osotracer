#pragma once

#include "Camera.h"
#include "Scene.h"

struct TraceOptions {
	int width;
	int height;
	int samples;
};

namespace Tracer {
	// renders image to the given buffer
	void render(const Camera& camera, const Scene& scene, const TraceOptions& options, unsigned char* buffer);

	// return the color of the traced ray
	color traceRay(const Scene& scene, const Ray& ray);
}
