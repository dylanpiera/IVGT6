#pragma once
#include "BuildingState.h"

/**
 * @brief The State a building should be in while under construction
 * 
 */
class ActiveState : public BuildingState
{
public:
	/**
	 * @brief Destroy the Active State object
	 * 
	 */
	~ActiveState();

	/**
	 * @brief Sets BuildingState to ActiveState
	 * 
	 * @param building 
	 */
	void BuildingActive(UBuilding* building);

	/**
	 * @brief Sets BuildingState to InactiveState
	 * 
	 * @param building 
	 */
	void BuildingInactive(UBuilding* building);

	/**
	 * @brief Sets BuildingState to ConstructionState
	 * 
	 * @param building 
	 */
	void BuildingConstruction(UBuilding* building);

	/**
	 * @brief Sets BuildingState to DestructionState
	 * 
	 * @param building 
	 */
	void BuildingDestruction(UBuilding* building);
};

