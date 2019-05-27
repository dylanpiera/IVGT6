#include "InactiveState.h"
#include "ActiveState.h"
#include "DestructionState.h"

InactiveState::InactiveState()
{
}


InactiveState::~InactiveState()
{
}

void InactiveState::BuildingActive(UBuilding* building)
{
	building->SetState(dynamic_cast<BuildingState*>(new ActiveState()));
}

void InactiveState::BuildingDestruction(UBuilding* building)
{
	building->SetState(dynamic_cast<BuildingState*>(new DestructionState()));
}

void InactiveState::BuildingInactive(UBuilding* building)
{
	return;
}

void InactiveState::BuildingConstruction(UBuilding* building)
{
	return;
}