#pragma once
#include "Building.h"

class HouseBuilding : public Building {
	int32 PopulationHousingValue = 8;

	void BuildingFunction(AEconomyManager& manager) {
		manager.resources._minerals = PopulationHousingValue;
	}
};