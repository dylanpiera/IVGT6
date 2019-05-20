#pragma once
#include "BuildingState.h"
class ConstructionState : public BuildingState
{
public:
	ConstructionState();
	~ConstructionState();

	void BuildingActive(BuildingObject* building);
	void BuildingDestruction(BuildingObject* building);
	void BuildingConstruction(BuildingObject* building);
	void BuildingInactive(BuildingObject* building);
};

