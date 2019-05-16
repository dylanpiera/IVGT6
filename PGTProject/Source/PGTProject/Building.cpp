#include "Building.h"

Building::Building() : _bState(new ConstructionState())
{

}

void Building::BuildingActive(Resources &resource, Resources &maintenance)
{
	BuildingFunction(resource);
	BuildingUpkeep(maintenance);
}

void Building::BuildingFunction(Resources &resource)
{
	resource._money -= 100;
}

void Building::BuildingUpkeep(Resources &resource)
{
}

void Building::BuildingInactive()
{
}

void Building::BuildingConstruction(float timeRequired)
{
}

void Building::BuildingDestruction()
{
}

void Building::SetState(BuildingState* state)
{
	_bState = state;

	/*if (state == ST_CONSTRUCTION)
	{
		// _bState = new ConstructionState();
	}
	else if (state == ST_ACTIVE)
	{
		// _bState = new ActiveState();
	}
	else if (state == ST_INACTIVE)
	{
		// _bState = new InactiveState();
	}
	else (state == ST_DESTRUCTION)
	{
		int i = 0;// _bState = new DestructionState();
	}*/
}

Building::~Building()
{
}
