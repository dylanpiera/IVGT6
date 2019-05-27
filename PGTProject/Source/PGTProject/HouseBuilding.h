#pragma once
#include "Building.h"

class HouseBuilding : public UBuilding {
	int32 PopulationHousingValue = 8;

	void BuildingFunction(Resources& resource) override {
		// Block building from producing while it's not done constructing
		if(_constructionState == EConstructionState::Done) {
			resource._population += PopulationHousingValue;
		}
	}
};