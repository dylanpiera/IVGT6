#pragma once
#include "Building.h"

class HouseBuilding : public Building {
	int32 PopulationHousingValue = 8;

	void BuildingFunction(Resources& resource) override {
		resource._population += PopulationHousingValue;
	}
};