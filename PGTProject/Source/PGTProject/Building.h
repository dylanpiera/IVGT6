#pragma once
#include "EconomyManager.h"

class Building {
public:
	
	/*
	 * override this and implement what the building needs to update
	*/
	virtual void BuildingFunction(AEconomyManager& manager) {

	}
};