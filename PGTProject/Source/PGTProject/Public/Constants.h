// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * @brief 
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
 * @brief 
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
 * @brief 
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
 * @brief 
 * 
 */
enum ToolbarSections
{
	RoadsSection,
	BuildingsSection
};

/**
 * @brief 
 * 
 */
enum class EMineralResources
{
	Catanium,
	NightGems
};

/**
 * @brief
 * 
 */
class PGTPROJECT_API Constants
{
public:
	Constants();
	~Constants();
};
