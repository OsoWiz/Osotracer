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

ScatterInfo Scene::getScatterInfo(const Ray& ray, HitInfo& hit, Ray* childRayStorage, int childRays)
{
	ScatterInfo scatterInfo; 
	Object* obj;

	if (objects->getClosestObjectHit(ray, obj, hit))
	{
		scatterInfo.numScatteredRays = childRays;
		hit.material->Scatter(ray, hit.normal, scatterInfo); // fill info
	}
	// if object did not intersect, return empty scatterinfo
	scatterInfo.numScatteredRays = 0; // zero rays scattered
	return scatterInfo;
}
