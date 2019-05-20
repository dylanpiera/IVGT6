#pragma once
#include "BuildingObject.h"

class MineralBuilding : public BuildingObject {

	int32 MineralProductionValue = 1;

	void BuildingFunction(Resources& resources) override {
		resources._minerals += MineralProductionValue;
	}
};