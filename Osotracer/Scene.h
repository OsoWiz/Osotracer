#pragma once
#include <vector>
#include <string>
#include <memory>
#include "ObjectDataStructure.h"

// some data structures later


class Scene
{
public:
	Scene(ObjectDataStructure& objects);
	~Scene();

	void addObject(Object& object);

	// Fills and returns the scatter info for the ray for given number of child rays
	ScatterInfo getScatterInfo(const Ray& ray, HitInfo& hit, Ray* childRayStorage, int childRays);
	
	// creates a scene from specified filepath
	static Scene fromFile(const std::string& filepath);

private:
	std::unique_ptr<ObjectDataStructure> objects; // list of objects in the scene
};
