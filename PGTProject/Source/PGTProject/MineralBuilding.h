#pragma once
#include "Building.h"

class MineralBuilding : public Building {

	int32 MineralProductionValue = 1;

	void BuildingFunction(Resources& resources) override {
		resources._minerals += MineralProductionValue;
	}
};