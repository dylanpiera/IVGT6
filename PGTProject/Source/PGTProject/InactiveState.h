#pragma once
#include "BuildingState.h"
class InactiveState : public BuildingState
{
public:
	InactiveState();
	~InactiveState();

	virtual void BuildingActive(Building* building);
	virtual void BuildingDestruction(Building* building);
};

