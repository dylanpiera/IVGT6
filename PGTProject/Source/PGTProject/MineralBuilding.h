#pragma once
#include "Building.h"

class MineralBuilding : public UBuilding {

	int32 MineralProductionValue = 1;

	void BuildingFunction(Resources& resource) override {
		resource._minerals += MineralProductionValue;
	}
};