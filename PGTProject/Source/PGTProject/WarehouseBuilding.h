#pragma once
#include "Building.h"

class WarehouseBuilding : public Building {

	void BuildingFunction(Resources& resources) override {
		resources._money -= 50;
	}
};