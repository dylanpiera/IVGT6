#pragma once

#include "CoreMinimal.h"

/**
 * @brief ENUM: Building types
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
 * @brief ENUM: Interaction modes
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
 * @brief ENUM: Toolbar options in each section
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
 * @brief ENUM: Toolbar sections
 * 
 */
enum ToolbarSections
{
	RoadsSection,
	BuildingsSection
};

/**
 * @brief ENUM: Types of mineral resources
 * 
 */
enum class EMineralResources
{
	Catanium,
	NightGems
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
