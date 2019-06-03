#pragma once
#include "Building.h"

class EnergyBuilding : public UBuilding {
	int32 EnergyProductionValue = 10;

	void BuildingFunction(Resources& resource) override {
		resource._energy += EnergyProductionValue;
	}
};