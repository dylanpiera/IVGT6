#include "ConstructionState.h"



ConstructionState::ConstructionState()
{
}


ConstructionState::~ConstructionState()
{
}

void ConstructionState::BuildingActive(BuildingObject * building)
{
	//building->SetState(dynamic_cast<BuildingState*>(new ActiveState()));
}

void ConstructionState::BuildingDestruction(BuildingObject * building)
{
	//building->SetState(dynamic_cast<BuildingState*>(new DestructionState()));
}

void ConstructionState::BuildingInactive(BuildingObject* building) {
	return;
}

void ConstructionState::BuildingConstruction(BuildingObject* building) {
	return;
}
