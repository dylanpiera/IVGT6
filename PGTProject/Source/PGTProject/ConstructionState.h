#pragma once
#include "BuildingState.h"

/**
 * @brief The State a building should be in while under construction
 * 
 */
class ConstructionState : public BuildingState
{
public:
	/**
	 * @brief Construct a new Construction State object
	 * 
	 */
	ConstructionState();
	/**
	 * @brief Destroy the Construction State object
	 * 
	 */
	~ConstructionState();

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

