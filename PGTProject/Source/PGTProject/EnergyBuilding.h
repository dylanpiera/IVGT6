#pragma once
#include "Building.h"

class EnergyBuilding : public Building {
	int32 EnergyProductionValue = 50;

	void BuildingFunction(Resources& resource) override {
		resource._energy += EnergyProductionValue;
	}
};