#pragma once
#include "Building.h"

class MineralBuilding : public Building {

	int32 MineralProductionValue = 1;

	void BuildingFunction(AEconomyManager& manager) {
		manager.resources._minerals = MineralProductionValue;
	}
};