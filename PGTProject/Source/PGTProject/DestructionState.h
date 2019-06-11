#pragma once
#include "BuildingState.h"

/**
 * @brief 
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
	 * @brief 
	 * 
	 * @param building 
	 */
	void BuildingActive(UBuilding* building);

	/**
	 * @brief 
	 * 
	 * @param building 
	 */
	void BuildingInactive(UBuilding* building);

	/**
	 * @brief 
	 * 
	 * @param building 
	 */
	void BuildingConstruction(UBuilding* building);

	/**
	 * @brief 
	 * 
	 * @param building 
	 */
	void BuildingDestruction(UBuilding* building);
};

