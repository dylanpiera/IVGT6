#pragma once
#include "Building.h"

class MineralBuilding : public UBuilding {

	int32 MineralProductionValue = 1;

	void BuildingFunction(Resources& resource) override {
		// Block building from producing while it's not done constructing
		if(_constructionState == EConstructionState::Done) {
			resource._minerals += MineralProductionValue;
		}
	}
};