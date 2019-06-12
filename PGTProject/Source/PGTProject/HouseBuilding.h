#pragma once
#include "Building.h"
#include "HouseBuilding.generated.h"

UCLASS()
/**
 * @brief  Set values affected by house building
 * 
 */
class PGTPROJECT_API UHouseBuilding : public UBuilding {
	GENERATED_BODY()
public:
	int32 PopulationHousingValue = 10;
	int EnergyUpkeep = 10;
	int Disdain = 0;

	/**
	 * @brief Adjust disdain value
	 * 
	 * @param resource 
	 */
	void BuildingFunction(Resources& resource) override {
		if (resource._food <= 0)
		{
			Disdain++;
		}
		else if (Disdain != 0)
		{
			Disdain--;
		}
	}

	/**
	 * @brief Set the Building Cost object
	 * 
	 */
	void SetBuildingCost() override {
		_buildingCost = 25;
	}
};