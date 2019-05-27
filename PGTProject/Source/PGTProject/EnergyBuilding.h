#pragma once
#include "Building.h"

class EnergyBuilding : public UBuilding {
	int32 EnergyProductionValue = 10;

	void BuildingFunction(Resources& resource) override {
		// Block building from producing while it's not done constructing
		if(_constructionState == EConstructionState::Done) {
			resource._energy += EnergyProductionValue;
		}
	}
};