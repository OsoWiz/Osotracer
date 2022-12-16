#pragma once

#include "Ray.h"
class Camera
{
public:
	/// <summary>
	/// Returns a ray for the given pixel coordinates
	/// </summary>
	/// <param name="normalizedScreen"> normalized screen cordinate</param>
	/// <returns></returns>
	virtual Ray getRay(glm::vec2 normalizedScreen) const = 0;
	Camera(glm::vec3 pos, glm::vec3 dir, glm::vec3 up);

protected:
	glm::vec3 pos, dir, up, right; //all the necessary stuff.
};


class PerspectiveCamera : public Camera
{
public:
	PerspectiveCamera(glm::vec3 pos, glm::vec3 dir, glm::vec3 up, float fov);
	Ray getRay(glm::vec2 normalizedScreen) const override;

private:
	float tanfov; //field of view in tan(radians/2)
};

class OrthogonalCamera : public Camera
{
public:
	OrthogonalCamera(glm::vec3 pos, glm::vec3 dir, glm::vec3 up, float width, float height);
	Ray getRay(glm::vec2 normalizedScreen) const override;

private:
	float width, height;
};