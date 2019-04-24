#pragma once
#include "Resources.h"

class Building {
public:
	
	/*
	 * override this and implement what the building needs to update
	*/
	virtual void BuildingFunction(Resources& resource) { }
};