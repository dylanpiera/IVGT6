#include "BuildingState.h"
#pragma once
class ConstructionState : public BuildingState
{
public:
	ConstructionState();
	~ConstructionState();

	virtual void BuildingActive(Building* building);
	virtual void BuildingDestruction(Building* building);
};

