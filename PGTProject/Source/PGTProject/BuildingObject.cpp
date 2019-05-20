#include "BuildingObject.h"

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

void BuildingObject::BuildingConstruction(float timeRequired)
{
}

void BuildingObject::BuildingDestruction()
{
}

BuildingObject::~BuildingObject()
{
}
