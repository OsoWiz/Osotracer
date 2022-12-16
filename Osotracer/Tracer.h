#pragma once

#include "Camera.h"
#include "Image.h"
#include "Scene.h"

struct TraceOptions {
	int width;
	int height;
	int samples;
};

namespace Tracer {
	void render(const Camera& camera, const Scene& scene, const TraceOptions& options);
	color traceRay(const Scene& scene, const Ray& ray);
}
