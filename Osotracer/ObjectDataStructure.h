#pragma once
#include <vector>
#include "Material.h"
#include "Object.h"

// interface which all ObjectDataStructure classes must implement
class ObjectDataStructure
{
public:
	virtual void addObject(Object* object) = 0;

	/**
	 * @brief Builds the data structure from the given list of objects.
	 * @param objects
	*/
	virtual void build(std::vector<Object*> objects) = 0;

};


class ObjectList : public ObjectDataStructure
{
public:
	ObjectList();
	~ObjectList();

	// Objects can only be added. Removing objects is not implemented yet
	void addObject(Object* object) override;

private:
	std::vector<Object*> container;
};