#pragma once
#include "Building.h"

class MineralBuilding : public Building {

	int32 MineralProductionValue = 5;
	int EnergyUpkeep = 20;
	int MoneyUpkeep = 10;

	void BuildingFunction(Resources& resources) override {
		resources._minerals += MineralProductionValue;
		resources._energy -= EnergyUpkeep;
		resources._money -= MoneyUpkeep;
	}
};