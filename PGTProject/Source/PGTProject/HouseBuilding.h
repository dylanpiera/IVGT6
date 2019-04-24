#pragma once
#include "Building.h"

class HouseBuilding : public Building {
	int32 PopulationHousingValue = 8;

	void BuildingFunction(Resources& resource) override {
		UE_LOG(LogTemp, Warning, TEXT("House Function ran!"));
		resource._population += PopulationHousingValue;
	}
};