#pragma once
#include "Building.h"
#include "HouseBuilding.generated.h"

UCLASS()
class PGTPROJECT_API UHouseBuilding : public UBuilding {
	GENERATED_BODY()
public:
	int32 PopulationHousingValue = 10;
	int EnergyUpkeep = 10;
	int Disdain = 0;

	void BuildingFunction(Resources& resource) override {
		//resource._energy -= EnergyUpkeep;
		if (resource._food == 0)
		{
			Disdain++;
		}
		else if (Disdain != 0)
		{
			Disdain--;
		}
	}

	void SetBuildingCost() override {
		UE_LOG(LogTemp, Warning, TEXT("Setting cost to 25"));
		_buildingCost = 25;
	}
};