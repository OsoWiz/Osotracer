#include "Camera.h"
Camera::Camera(glm::vec3 pos, glm::vec3 dir, glm::vec3 up)
	:pos(pos), dir(dir), up(up)
{
	right = glm::normalize(glm::cross(dir, up));
}
PerspectiveCamera::PerspectiveCamera(glm::vec3 pos, glm::vec3 dir, glm::vec3 up, float fov)
	:Camera(pos, dir, up), tanfov(tan(fov / 2))
{
}
Ray PerspectiveCamera::getRay(glm::vec2 normalizedScreen)
{
	Ray ray{};
	ray.origin = pos;
	glm::vec3 rdelta = normalizedScreen.x * right;
	glm::vec3 udelta = normalizedScreen.y * up;
	ray.direction = glm::normalize(tanfov * dir + rdelta + udelta);
	return ray;
}

OrthogonalCamera::OrthogonalCamera(glm::vec3 pos, glm::vec3 dir, glm::vec3 up, float width, float height)
	:Camera(pos, dir, up),width(width), height(height)
{	
}

Ray OrthogonalCamera::getRay(glm::vec2 normalizedScreen)
{
	Ray ray{};
	glm::vec3 updelta = up * normalizedScreen.y * height;
	glm::vec3 rightdelta = right * normalizedScreen.x * width;

	ray.origin = pos + rightdelta + updelta;
	ray.direction = dir;
	return ray;
}


