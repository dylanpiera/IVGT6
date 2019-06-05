#pragma once
#include "BuildingState.h"
class DestructionState : public BuildingState
{
public:
	DestructionState();
	~DestructionState();

	/**
	 * See: BuildingState.h - Line 20
	*/
	void BuildingActive(UBuilding* building);

	/**
	 * See: BuildingState.h - Line 26
	*/
	void BuildingInactive(UBuilding* building);

	/**
	 * See: BuildingState.h - Line 32
	*/
	void BuildingConstruction(UBuilding* building);

	/**
	 * See: BuildingState.h - Line 38
	*/
	void BuildingDestruction(UBuilding* building);
};

