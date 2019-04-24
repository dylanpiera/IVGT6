#pragma once
#include "Building.h"

class EnergyBuilding : public Building {
	int32 EnergyProductionValue = 10;

	void BuildingFunction(AEconomyManager& manager) {
		manager.resources._minerals = EnergyProductionValue;
	}
};