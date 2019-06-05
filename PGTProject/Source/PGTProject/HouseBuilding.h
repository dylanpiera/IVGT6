#pragma once
#include "Building.h"
#include "HouseBuilding.generated.h"

UCLASS()
class PGTPROJECT_API UHouseBuilding : public UBuilding {
	GENERATED_BODY()
public:
	int Disdain = 0;

	void BuildingFunction(Resources& resource) override {
		//resource._energy -= EnergyUpkeep;
		if (resource._food <= 0)
		{
			Disdain++;
		}
		else if (Disdain != 0)
		{
			Disdain--;
		}
		if (Disdain > 0)
		{
			resource._population--;
		}
		resource._money += (resource._population * 2);
	}
};