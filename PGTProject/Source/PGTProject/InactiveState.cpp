#include "InactiveState.h"



InactiveState::InactiveState()
{
}


InactiveState::~InactiveState()
{
}

void InactiveState::BuildingActive(Building* building)
{
	building->SetState(new ActiveState());
}

void InactiveState::BuildingDestruction(Building* building)
{
	building->SetState(new DestructionState());
}
