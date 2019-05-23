#include "ActiveState.h"
#include "InactiveState.h"
#include "DestructionState.h"


ActiveState::~ActiveState()
{
}

void ActiveState::BuildingInactive(BuildingObject* building)
{
	building->SetState(dynamic_cast<BuildingState*>(new InactiveState()));
}

void ActiveState::BuildingDestruction(BuildingObject* building)
{
	building->SetState(dynamic_cast<BuildingState*>(new DestructionState()));
}

void ActiveState::BuildingActive(BuildingObject* building)
{
	return;
}

void ActiveState::BuildingConstruction(BuildingObject* building)
{
	return;
}