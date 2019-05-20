#pragma once
#include "BuildingObject.h"

class HouseBuilding : public BuildingObject {
	int32 PopulationHousingValue = 8;

	void BuildingFunction(Resources& resource) override {
		resource._population += PopulationHousingValue;
	}
};