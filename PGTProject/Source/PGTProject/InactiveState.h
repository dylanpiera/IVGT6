#pragma once
#include "BuildingState.h"

/**
 * @brief The State a building should be in while inactive
 * 
 */
class InactiveState : public BuildingState
{
public:
	/**
	 * @brief Construct a new Inactive State object
	 * 
	 */
	InactiveState();
	/**
	 * @brief Destroy the Inactive State object
	 * 
	 */
	~InactiveState();

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

