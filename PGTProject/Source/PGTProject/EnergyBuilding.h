#pragma once
#include "Building.h"

class EnergyBuilding : public Building {
	int32 EnergyProductionValue = 10;

	void BuildingFunction(Resources& resource) override {
		UE_LOG(LogTemp, Warning, TEXT("Energy Function ran!"));
		resource._energy += EnergyProductionValue;
	}
};