#pragma once
#include "Building.h"

class MineralBuilding : public UBuilding {
	int32 MineralProductionValue = 5;
	int EnergyUpkeep = 20;
	int MoneyUpkeep = 10;

	void BuildingFunction(Resources& resource) override {
		if (resource._energy != 0)
		{
			resource._minerals += MineralProductionValue;
			resource._energy -= EnergyUpkeep;
			resource._money -= MoneyUpkeep;
		}
	}
};