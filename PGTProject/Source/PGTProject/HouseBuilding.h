#pragma once
#include "Building.h"

class HouseBuilding : public UBuilding {
	int32 PopulationHousingValue = 10;
	int EnergyUpkeep = 10;
	int Disdain = 0;

	void BuildingFunction(Resources& resource) override {
		resource._energy -= EnergyUpkeep;
		if (resource._food == 0)
		{
			Disdain++;
		}
		else if (Disdain != 0)
		{
			Disdain--;
		}
	}
};