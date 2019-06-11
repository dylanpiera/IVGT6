#pragma once
#include "BuildingState.h"

/**
 * @brief 
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

