// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

enum class EBuildingType
{
	Mineral,
	Energy,
	House,
	Road
};

enum class EInteractionMode
{
	Insert,
	Select,
	Edit,
	Delete
};

enum OptionSections
{
	RoughRoad,
	EnergyBuilding,
	MineralsBuilding,
	MoneyBuilding,
	DestroyTool
};

// Toolbar structure definitions
enum ToolbarSections
{
	RoadsSection,
	BuildingsSection
};

// Avaiable resources
enum class EMineralResources
{
	Catanium,
	NightGems
};

/**
 *
 */
class PGTPROJECT_API Constants
{
public:
	Constants();
	~Constants();
};
