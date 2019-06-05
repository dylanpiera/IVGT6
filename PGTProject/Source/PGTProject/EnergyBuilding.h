#pragma once
#include "Building.h"
#include "EconomyManager.h"
#include "EnergyBuilding.generated.h"

UCLASS()
class PGTPROJECT_API UEnergyBuilding : public UBuilding {
	GENERATED_BODY()
public:
	int MoneyUpkeep = 25;

	void BuildingFunction(Resources& resource) override {
		if (resource._money > 0)
		{
			resource._money -= MoneyUpkeep;
		}
	}
};