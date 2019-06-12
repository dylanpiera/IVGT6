#pragma once
#include "Building.h"
#include "MineralBuilding.generated.h"

UCLASS()
/**
 * @brief Set values affected by mineral building
 * 
 */
class PGTPROJECT_API UMineralBuilding : public UBuilding {
	GENERATED_BODY()
public:
	int32 MineralProductionValue = 5;
	int EnergyUpkeep = 20;
	int MoneyUpkeep = 10;

	/**
	 * @brief  Set values affected by mineral building during the game
	 * 
	 * @param resource 
	 */
	void BuildingFunction(Resources &resource) override
	{
		if (resource._energy >= 0)
		{
			resource._minerals += MineralProductionValue;
		}
		resource._money -= MoneyUpkeep;
	}

	/**
	 * @brief Set the Building Cost object
	 * 
	 */
	void SetBuildingCost() override {
		_buildingCost = 50;
	}
};