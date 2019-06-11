#pragma once

#include "CoreMinimal.h"

/**
 * @brief enum of building types
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
 * @brief enum of interaction modes
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
 * @brief Option Sections reference enum to the Bottem ToolBar
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
 * @brief enum to buildings or road
 * 
 */
enum ToolbarSections
{
	RoadsSection,
	BuildingsSection
};

/**
 * @brief enum of Minerals
 * 
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
