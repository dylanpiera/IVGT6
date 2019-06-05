#pragma once
#include "Building.h"
#include "FoodBuilding.generated.h"

UCLASS()
class PGTPROJECT_API UFoodBuilding : public UBuilding {
	GENERATED_BODY()
public:
	int32 FoodProductionValue = 15;

	void BuildingFunction(Resources& resource) override {
		if (resource._energy != 0)
		{
			resource._food += FoodProductionValue - resource._population;
		}
	}
};