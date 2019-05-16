#include "ActiveState.h"



ActiveState::ActiveState()
{
}


ActiveState::~ActiveState()
{
}

void ActiveState::BuildingInactive(Building* building)
{
	building->SetState(new InactiveState());
}

void ActiveState::BuildingDestruction(Building* building)
{
	building->SetState(new DestructionState());
}
