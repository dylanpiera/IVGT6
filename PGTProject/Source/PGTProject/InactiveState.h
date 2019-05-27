#pragma once
#include "BuildingState.h"
class InactiveState : public BuildingState
{
public:
	InactiveState();
	~InactiveState();

	/**
	 * See: BuildingState.h - Line 20
	*/
	void BuildingActive(BuildingObject* building);

	/**
	 * See: BuildingState.h - Line 26
	*/
	void BuildingInactive(BuildingObject* building);

	/**
	 * See: BuildingState.h - Line 32
	*/
	void BuildingConstruction(BuildingObject* building);

	/**
	 * See: BuildingState.h - Line 38
	*/
	void BuildingDestruction(BuildingObject* building);
};

