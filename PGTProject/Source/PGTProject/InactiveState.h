#pragma once
#include "BuildingState.h"
class InactiveState : public BuildingState
{
public:
	InactiveState();
	~InactiveState();

	void BuildingActive(BuildingObject* building);
	void BuildingInactive(BuildingObject* building);
	void BuildingConstruction(BuildingObject* building);
	void BuildingDestruction(BuildingObject* building);
};

