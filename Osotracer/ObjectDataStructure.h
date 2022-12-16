#pragma once
# include <vector>
# include "Ray.h"
#include "Object.h"

// interface which all ObjectDataStructure classes must implement
class ObjectDataStructure
{
public:
	virtual void addObject(Object* object) = 0;
	
	virtual bool getClosestObject(const Ray& ray, Object& o) = 0;
	
};


class ObjectList : public ObjectDataStructure
{
public:
	ObjectList();
	~ObjectList();

	// Objects can only be added. Removing objects is not implemented yet
	void addObject(Object* object) override;

	/*
	* @brief Sets o to the closest object to the ray if one exists.Returns boolean indicating whether the ray hit an object
	* @param ray Ray to check for intersection
	* @param o Object to set to the closest object
	*/ 
	bool getClosestObject(const Ray& ray, Object& o) override;
	
private:
	std::vector<Object*> container;
};