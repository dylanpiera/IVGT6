#pragma once
#include "Building.h"
#include "EconomyManager.h"

class EnergyBuilding : public Building {
	int32 EnergyProductionValue = 50;
	int MoneyUpkeep = 25;

	void BuildingFunction(Resources& resource) override {
		resource._energy += EnergyProductionValue;
		resource._money -= MoneyUpkeep;
	}
};