#pragma once
#include "Building.h"

class FoodBuilding : public UBuilding {
	int32 FoodProductionValue = 15;
	int EnergyUpkeep = 5;

	void BuildingFunction(Resources& resource) override {
		if (resource._energy != 0)
		{
			resource._food += FoodProductionValue - resource._population;
			resource._energy -= EnergyUpkeep;
		}
	}
};