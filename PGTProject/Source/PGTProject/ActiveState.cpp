#include "ActiveState.h"
#include "InactiveState.h"
#include "DestructionState.h"


ActiveState::~ActiveState()
{
}

void ActiveState::BuildingInactive(UBuilding* building)
{
	building->SetState(dynamic_cast<BuildingState*>(new InactiveState()));
}

void ActiveState::BuildingDestruction(UBuilding* building)
{
	building->SetState(dynamic_cast<BuildingState*>(new DestructionState()));
}

void ActiveState::BuildingActive(UBuilding* building)
{
	return;
}

void ActiveState::BuildingConstruction(UBuilding* building)
{
	return;
}