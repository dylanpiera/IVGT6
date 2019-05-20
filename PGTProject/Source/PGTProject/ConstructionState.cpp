#include "ConstructionState.h"
#include "ActiveState.h"
#include "DestructionState.h"


ConstructionState::ConstructionState()
{
}


ConstructionState::~ConstructionState()
{
}

void ConstructionState::BuildingActive(BuildingObject * building)
{
	building->SetState(new ActiveState());
}

void ConstructionState::BuildingDestruction(BuildingObject * building)
{
	building->SetState(new DestructionState());
}

void ConstructionState::BuildingInactive(BuildingObject* building) {
	return;
}

void ConstructionState::BuildingConstruction(BuildingObject* building) {
	return;
}
