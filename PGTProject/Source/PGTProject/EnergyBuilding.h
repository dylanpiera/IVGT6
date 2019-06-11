#pragma once
#include "Building.h"
#include "EconomyManager.h"
#include "EnergyBuilding.generated.h"

UCLASS()
/**
 * @brief 
 * 
 */
class PGTPROJECT_API UEnergyBuilding : public UBuilding {
	GENERATED_BODY()
public:
	int32 EnergyProductionValue = 50;
	int MoneyUpkeep = 25;

	/**
	 * @brief 
	 * 
	 * @param resource 
	 */
	void BuildingFunction(Resources& resource) override {
		//resource._energy += EnergyProductionValue;
		resource._money -= MoneyUpkeep;
	}

	/**
	 * @brief Set the Building Cost object
	 * 
	 */
	void SetBuildingCost() override {
		UE_LOG(LogTemp, Warning, TEXT("Setting cost to 100"));
		_buildingCost = 100;
	}
};