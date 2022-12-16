#include "Scene.h"

Scene::Scene(ObjectDataStructure& objects) : objects(&objects)
{
}

Scene::~Scene()
{
}

void Scene::addObject(Object& object)
{
	objects->addObject(&object);
}
