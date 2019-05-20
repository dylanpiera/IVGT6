#include "ActiveState.h"
#include "InactiveState.h"
#include "DestructionState.h"


ActiveState::ActiveState()
{
}


ActiveState::~ActiveState()
{
}

void ActiveState::BuildingInactive(BuildingObject* building)
{
	building->SetState(new InactiveState());
}

void ActiveState::BuildingDestruction(BuildingObject* building)
{
	building->SetState(new DestructionState());
}

void ActiveState::BuildingActive(BuildingObject* building)
{
	return;
}

void ActiveState::BuildingConstruction(BuildingObject* building)
{
	return;
}