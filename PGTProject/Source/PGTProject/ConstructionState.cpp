#include "ConstructionState.h"
#include "ActiveState.h"
#include "DestructionState.h"


ConstructionState::ConstructionState()
{
}


ConstructionState::~ConstructionState()
{
}

void ConstructionState::BuildingActive(UBuilding * building)
{
	building->SetState(dynamic_cast<BuildingState*>(new ActiveState()));
}

void ConstructionState::BuildingDestruction(UBuilding * building)
{
	building->SetState(dynamic_cast<BuildingState*>(new DestructionState()));
}

void ConstructionState::BuildingInactive(UBuilding* building) {
	return;
}

void ConstructionState::BuildingConstruction(UBuilding* building) {
	return;
}
