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

	// Get's the hit information of traced ray into the scene
	HitInfo getHitInfo(const Ray& ray);

	// creates a scene from specified filepath
	static Scene fromFile(const std::string& filepath);



private:
	std::unique_ptr<ObjectDataStructure> objects; // ObjectDataStructure holding all objects in the scene
};
