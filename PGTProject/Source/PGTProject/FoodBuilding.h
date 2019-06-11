#pragma once
#include "Building.h"
#include "FoodBuilding.generated.h"

UCLASS()
/**
 * @brief 
 * 
 */
class PGTPROJECT_API UFoodBuilding : public UBuilding {
	GENERATED_BODY()
public:
	int32 FoodProductionValue = 15;
	int EnergyUpkeep = 5;

	/**
	 * @brief 
	 * 
	 * @param resource 
	 */
	void BuildingFunction(Resources& resource) override {
		//resource._energy -= EnergyUpkeep;
		if (resource._energy >= 0)
		{
			resource._food += FoodProductionValue - resource._population;
		}
	}

	/**
	 * @brief Set the Building Cost object
	 * 
	 */
	void SetBuildingCost() override {
		UE_LOG(LogTemp, Warning, TEXT("Setting cost to 20"));
		_buildingCost = 20;
	}
};