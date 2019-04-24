#pragma once
#include "Building.h"

class MineralBuilding : public Building {

	int32 MineralProductionValue = 1;

	void BuildingFunction(Resources& resources) override {
		UE_LOG(LogTemp, Warning, TEXT("Mineral Function ran!"));
		resources._minerals += MineralProductionValue;
	}
};