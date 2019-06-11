#pragma once
#include "BuildingState.h"

/**
 * @brief The State a building should be in while being destroyed
 * 
 */
class DestructionState : public BuildingState
{
public:
	/**
	 * @brief Construct a new Destruction State object
	 * 
	 */
	DestructionState();
	/**
	 * @brief Destroy the Destruction State object
	 * 
	 */
	~DestructionState();

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

