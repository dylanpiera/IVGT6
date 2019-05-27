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

enum class EConstructionState
{
	Created,
	Constructing,
	Done
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
