#pragma once
#include "Building.h"

class FoodBuilding : public Building {
	int32 FoodProductionValue = 15;
	int EnergyUpkeep = 5;

	void BuildingFunction(Resources& resource) override {
		resource._food += FoodProductionValue - resource._population;
		resource._energy -= EnergyUpkeep;
	}
};