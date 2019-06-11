#pragma once
#include "BuildingState.h"

/**
 * @brief 
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
	 * See: BuildingState.h - Line 20
	*/

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

