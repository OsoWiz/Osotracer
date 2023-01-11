#include "ObjectDataStructure.h"



ObjectList::ObjectList()
{
}

ObjectList::~ObjectList()
{
	for (auto& o : container)
	{
		delete o;
	}
}

void ObjectList::addObject(Object* object)
{
	container.push_back(object);
}

bool ObjectList::getClosestObjectHit(const Ray& ray, Object& o, HitInfo& hit)
{
	bool succ = false;
	// Initialize to first object
	if (container.size() == 0)
		return succ;
	
	hit.t = std::numeric_limits<float>::max();
	
	for (size_t i = 0; i < container.size(); i++) {
		HitInfo newhit;
		// if no intersection happened, continue
		if (!container[i]->intersect(ray, newhit))
			continue;
		
		if (newhit.t < hit.t)
		{
			hit = newhit; // Check if this copy actually works. Should work in theory
			o = *container[i];
			succ = true;
		}
		
	}
	return succ;
}
