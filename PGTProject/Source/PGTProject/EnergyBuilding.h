#pragma once
#include "Building.h"
#include "EconomyManager.h"
#include "EnergyBuilding.generated.h"

UCLASS()
/**
 * @brief  Set values affected by energy building
 * 
 */
class PGTPROJECT_API UEnergyBuilding : public UBuilding {
	GENERATED_BODY()
public:
	int32 EnergyProductionValue = 50;
	int MoneyUpkeep = 25;

	/**
	 * @brief Remove upkeep costs
	 * 
	 * @param resource 
	 */
	void BuildingFunction(Resources& resource) override {
		resource._money -= MoneyUpkeep;
	}

	/**
	 * @brief Set the Building Cost object
	 * 
	 */
	void SetBuildingCost() override {
		_buildingCost = 100;
	}
};