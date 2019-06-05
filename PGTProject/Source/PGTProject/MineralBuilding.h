#pragma once
#include "Building.h"
#include "MineralBuilding.generated.h"

UCLASS()
class PGTPROJECT_API UMineralBuilding : public UBuilding {
	GENERATED_BODY()
public:
	int32 MineralProductionValue = 5;
	int MoneyUpkeep = 10;

	void BuildingFunction(Resources &resource) override
	{
		if (resource._energy > 0 && resource._money > 0)
		{
			resource._minerals += MineralProductionValue;
			resource._money -= MoneyUpkeep;
		}
	}
};