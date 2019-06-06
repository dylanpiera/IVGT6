#pragma once
#include "Building.h"
#include "MineralBuilding.generated.h"

UCLASS()
class PGTPROJECT_API UMineralBuilding : public UBuilding {
	GENERATED_BODY()
public:
	int32 MineralProductionValue = 5;
	int EnergyUpkeep = 20;
	int MoneyUpkeep = 10;

	void BuildingFunction(Resources &resource) override
	{
		//resource._energy -= EnergyUpkeep;
		if (resource._energy >= 0)
		{
			resource._minerals += MineralProductionValue;
		}
		resource._money -= MoneyUpkeep;
	}

	void SetBuildingCost() override {
		UE_LOG(LogTemp, Warning, TEXT("Setting cost to 50"));
		_buildingCost = 50;
	}
};