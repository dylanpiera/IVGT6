#pragma once
#include "BuildingState.h"
class ActiveState : public BuildingState
{
public:
	ActiveState();
	~ActiveState();

	virtual void BuildingInactive(Building* building);
	virtual void BuildingDestruction(Building* building);
};

