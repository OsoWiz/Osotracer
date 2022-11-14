#pragma once
#include <vector>

class Scene
{
public:
	Scene();
	~Scene();
	private
		std::vector<Object> objects; // list of objects in the scene
};

