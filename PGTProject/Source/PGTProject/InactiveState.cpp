#include "InactiveState.h"
#include "ActiveState.h"
#include "DestructionState.h"

InactiveState::InactiveState()
{
}


InactiveState::~InactiveState()
{
}

void InactiveState::BuildingActive(BuildingObject* building)
{
	building->SetState(dynamic_cast<BuildingState*>(new ActiveState()));
}

void InactiveState::BuildingDestruction(BuildingObject* building)
{
	building->SetState(dynamic_cast<BuildingState*>(new DestructionState()));
}

void InactiveState::BuildingInactive(BuildingObject* building)
{
	return;
}

void InactiveState::BuildingConstruction(BuildingObject* building)
{
	return;
}