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
	building->SetState(new ActiveState());
}

void InactiveState::BuildingDestruction(BuildingObject* building)
{
	building->SetState(new DestructionState());
}

void InactiveState::BuildingInactive(BuildingObject* building)
{
	return;
}

void InactiveState::BuildingConstruction(BuildingObject* building)
{
	return;
}