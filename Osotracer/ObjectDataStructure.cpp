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