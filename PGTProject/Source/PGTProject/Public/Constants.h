#pragma once

#include "CoreMinimal.h"

/**
 * @enum Building types 
 * 
 */
enum class EBuildingType
{
	Mineral,
	Energy,
	House,
	Road
};

/**
 * @enum Interaction modes
 * 
 */
enum class EInteractionMode
{
	Insert,
	Select,
	Edit,
	Delete
};

/**
 * @enum Toolbar Options
 * @brief Define the toolbar options for each toolbar section
 * 
 */
enum OptionSections
{
	RoughRoad,
	EnergyBuilding,
	MineralsBuilding,
	MoneyBuilding,
	FoodBuilding,
	DestroyTool
};

/**
 * @enum Toolbar sections
 * @brief Define the toolbar sections
 * 
 */
enum ToolbarSections
{
	RoadsSection,
	BuildingsSection
};

/**
 * @enum Types of mineral resources
 * @brief Define all mineral resources
 */
enum class EMineralResources
{
	Catanium,
	NightGems
};

// Builders Availability Status
enum class EWorkState
{
	Free,
	Walking,
	Working
};

/**
 * @brief Simple collection of constants
 * 
 */
class PGTPROJECT_API Constants
{
public:



	Constants();
	~Constants();
};
