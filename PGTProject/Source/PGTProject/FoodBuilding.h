#pragma once
#include "Building.h"

class FoodBuilding : public Building {
	int32 FoodProductionValue = 15;

	void BuildingFunction(Resources& resource) override {
		resource._food += FoodProductionValue - resource._population;
	}
};