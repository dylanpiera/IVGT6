// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Building.h"
#include "CoreMinimal.h"

/**
 * 
 */
class PGTPROJECT_API BuildingState
{
public:
	BuildingState();
	~BuildingState();

	virtual void BuildingActive(Building* building);
	virtual void BuildingInactive(Building* building);
	virtual void BuildingConstruction(Building* building);
	virtual void BuildingDestruction(Building* building);
};
