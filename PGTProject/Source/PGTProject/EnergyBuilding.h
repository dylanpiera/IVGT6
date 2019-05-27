#pragma once
#include "BuildingObject.h"

class EnergyBuilding : public BuildingObject {
	int32 EnergyProductionValue = 10;

	void BuildingFunction(Resources& resource) override {
		resource._energy += EnergyProductionValue;
	}
};