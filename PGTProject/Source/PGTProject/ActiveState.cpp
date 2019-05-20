#include "ActiveState.h"



ActiveState::ActiveState()
{
}


ActiveState::~ActiveState()
{
}

void ActiveState::BuildingInactive(BuildingObject* building)
{
	return;
	//building->SetState(dynamic_cast<BuildingState*>(new InactiveState()));
}

void ActiveState::BuildingDestruction(BuildingObject* building)
{
	return;
	//building->SetState(dynamic_cast<BuildingState*>(new DestructionState()));
}

void ActiveState::BuildingActive(BuildingObject* building)
{
	return;
}

void ActiveState::BuildingConstruction(BuildingObject* building)
{
	return;
}