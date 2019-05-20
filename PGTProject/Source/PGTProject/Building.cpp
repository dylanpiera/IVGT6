#include "Building.h"

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

//void Building::SetState(BuildingState* state)
//{
//	_bState = state;
//}

Building::~Building()
{
}
