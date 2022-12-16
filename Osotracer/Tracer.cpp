#include "Tracer.h"

void Tracer::render(const Camera& camera, const Scene& scene, const TraceOptions& options, unsigned char* buffer)
{
	for (size_t y = 0; y < options.height; y++)
	{
		for (size_t x = 0; x < options.width; x++)
		{
			Ray ray = camera.getRay(glm::vec2(x, y));
			color c = traceRay(scene, ray); // TODO get hit information
			
			
		}
	}
}

color Tracer::traceRay(const Scene& scene, const Ray& ray)
{
	return color{ 255, 0, 0 };
}
