#include "Tracer.h"

void Tracer::render(const Camera& camera, const Scene& scene, const TraceOptions& options, unsigned char* buffer)
{
	for (size_t y = 0; y < options.height; y++)
	{
		for (size_t x = 0; x < options.width; x++)
		{
			Ray ray = camera.getRay(glm::vec2(x, y));
			int startDepth = int(options.maxDepth);
			Colors::color c = Tracer::traceRayRecursive(scene, ray, startDepth); // TODO get hit information or smth and use sampler
			
			// write to the buffer
			buffer[(y * options.width + x) * 3 + 0] = c.r;
			buffer[(y * options.width + x) * 3 + 1] = c.g;
			buffer[(y * options.width + x) * 3 + 2] = c.b;
		}
	}
}

Colors::color Tracer::traceRay(const Scene& scene, const Ray& ray, int depth)
{
	// Do tracing
	
	
	
	return Colors::color{ 255, 0, 0 };
}

Colors::color Tracer::traceRayRecursive(const Scene& scene, const Ray& ray, int depth)
{

	
	return Colors::color();
}
