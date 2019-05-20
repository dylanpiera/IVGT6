#pragma once
#include "BuildingState.h"
class DestructionState : public BuildingState
{
public:
	DestructionState();
	~DestructionState();

	void BuildingActive(BuildingObject* building);
	void BuildingInactive(BuildingObject* building);
	void BuildingConstruction(BuildingObject* building);
	void BuildingDestruction(BuildingObject* building);
};

