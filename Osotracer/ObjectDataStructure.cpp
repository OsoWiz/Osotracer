#include "ObjectDataStructure.h"



ObjectList::ObjectList()
{
}

ObjectList::~ObjectList()
{
}

void ObjectList::addObject(Object* object)
{
	container.push_back(object);
}

bool ObjectList::getClosestObject(const Ray& ray, Object& o)
{
	bool succ = false;
	// Initialize to first object
	if (container.size() == 0)
		return succ;
	
	float shortestHit = std::numeric_limits<float>::max();
	
	
	for (size_t i = 0; i < container.size(); i++) {
		float dist = 0.f;
		// if no intersection happened, continue
		if (!container[i]->intersect(ray, dist))
			continue;
		
		if (dist < shortestHit)
		{
			shortestHit = dist;
			//o = container[i]; error
		}
		
	}
	return succ;
}
