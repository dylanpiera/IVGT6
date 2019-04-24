#pragma once
#include "Building.h"

class HouseBuilding : public Building {
	int32 PopulationHousingValue = 8;

	void BuildingFunction(Resources& resource) {
		resource._population += PopulationHousingValue;
	}
};