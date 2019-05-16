#pragma once
#include "InactiveState.h"
#include "ConstructionState.h"
#include "DestructionState.h"
#include "ActiveState.h"
#include "BuildingState.h"
#include "Resources.h"

class Building {
public:

	/*enum State
	{
		ST_CONSTRUCTION,
		ST_ACTIVE,
		ST_INACTIVE,
		ST_DESTRUCTION
	};*/
	
	/*
	 * override this and implement what the building needs to update
	*/
	virtual void BuildingActive(Resources &resource, Resources &maintenance);

	virtual void BuildingFunction(Resources &resource);

	virtual void BuildingUpkeep(Resources &resource);

	virtual void BuildingInactive();

	virtual void BuildingConstruction(float buildTime);

	virtual void BuildingDestruction();

	void SetState(BuildingState* state);

	virtual ~Building();

private:

	BuildingState *_bState;
};