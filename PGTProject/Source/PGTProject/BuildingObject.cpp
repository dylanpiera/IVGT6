#include "BuildingObject.h"
#include "ConstructionState.h"
#include "ActiveState.h"

BuildingObject::BuildingObject()
{
	_bState = new ActiveState();
}

void BuildingObject::BuildingActive(Resources &resource, Resources &maintenance)
{
	BuildingFunction(resource);
	BuildingUpkeep(maintenance);
}

void BuildingObject::BuildingFunction(Resources &resource)
{
	resource._money -= 100;
}

void BuildingObject::BuildingUpkeep(Resources &resource)
{
}

void BuildingObject::BuildingInactive()
{
}

void BuildingObject::BuildingConstruction(float buildTime)
{
}

void BuildingObject::BuildingDestruction()
{
}

void BuildingObject::SetState(BuildingState * state)
{
	_bState = state;
}

BuildingState * BuildingObject::GetState()
{
	return _bState;
}

BuildingObject::~BuildingObject()
{
}

