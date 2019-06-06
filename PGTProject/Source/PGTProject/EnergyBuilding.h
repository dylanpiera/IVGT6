#pragma once
#include "Building.h"
#include "EconomyManager.h"
#include "EnergyBuilding.generated.h"

UCLASS()
class PGTPROJECT_API UEnergyBuilding : public UBuilding {
	GENERATED_BODY()
public:
	int32 EnergyProductionValue = 50;
	int MoneyUpkeep = 25;

	void BuildingFunction(Resources& resource) override {
		//resource._energy += EnergyProductionValue;
		resource._money -= MoneyUpkeep;
	}

	void SetBuildingCost() override {
		UE_LOG(LogTemp, Warning, TEXT("Setting cost to 100"));
		_buildingCost = 100;
	}
};