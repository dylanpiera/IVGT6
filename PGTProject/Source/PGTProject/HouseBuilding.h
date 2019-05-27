#pragma once
#include "Building.h"

class HouseBuilding : public Building {
	int32 PopulationHousingValue = 10;
	int EnergyUpkeep = 10;

	void BuildingFunction(Resources& resource) override {
		resource._energy -= EnergyUpkeep;
	}
};