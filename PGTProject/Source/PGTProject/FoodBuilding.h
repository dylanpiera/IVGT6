#pragma once
#include "Building.h"

class FoodBuilding : public Building {
	int32 FoodProductionHousingValue = 8;

	void BuildingFunction(Resources& resource) override {
		resource._food += FoodProductionHousingValue;
	}
};

