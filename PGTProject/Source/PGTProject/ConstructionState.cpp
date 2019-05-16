#include "ConstructionState.h"



ConstructionState::ConstructionState()
{
}


ConstructionState::~ConstructionState()
{
}

void ConstructionState::BuildingActive(Building * building)
{
	building->SetState(new ActiveState());
}

void ConstructionState::BuildingDestruction(Building * building)
{
	building->SetState(new DestructionState());
}
