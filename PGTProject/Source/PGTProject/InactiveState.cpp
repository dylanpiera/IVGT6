#include "InactiveState.h"
#include "ActiveState.h"
#include "DestructionState.h"

/**
 * @brief Construct a new Inactive State:: Inactive State object
 * 
 */
InactiveState::InactiveState()
{
}

/**
 * @brief Destroy the Inactive State:: Inactive State object
 * 
 */
InactiveState::~InactiveState()
{
}

/**
 * @brief 
 * 
 * @param building 
 */
void InactiveState::BuildingActive(UBuilding* building)
{
	building->SetState(dynamic_cast<BuildingState*>(new ActiveState()));
}

/**
 * @brief 
 * 
 * @param building 
 */
void InactiveState::BuildingDestruction(UBuilding* building)
{
	building->SetState(dynamic_cast<BuildingState*>(new DestructionState()));
}

/**
 * @brief 
 * 
 * @param building 
 */
void InactiveState::BuildingInactive(UBuilding* building)
{
	return;
}

/**
 * @brief 
 * 
 * @param building 
 */
void InactiveState::BuildingConstruction(UBuilding* building)
{
	return;
}