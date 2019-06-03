#pragma once
#include "Building.h"

class HouseBuilding : public UBuilding {
	int32 PopulationHousingValue = 8;

	void BuildingFunction(Resources& resource) override {
		resource._population += PopulationHousingValue;
	}
};