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
	
	// creates a scene from specified filepath
	static Scene fromFile(const std::string& filepath);

	

private:
	std::unique_ptr<ObjectDataStructure> objects; // list of objects in the scene
};
