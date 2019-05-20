#pragma once
#include "BuildingState.h"

class ActiveState : public BuildingState
{
public:
	ActiveState();
	~ActiveState();

	void BuildingActive(BuildingObject* building);
	void BuildingInactive(BuildingObject* building);
	void BuildingConstruction(BuildingObject* building);
	void BuildingDestruction(BuildingObject* building);
};

