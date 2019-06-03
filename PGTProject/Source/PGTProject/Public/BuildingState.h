// Fill out your copyright notice in the Description page of Project Settings.

#ifndef BuildingState_Header
#define BuildingState_Header
#include "Building.h"
#include <typeinfo>
#include "CoreMinimal.h"

/**
 * Polymorphic Parent of all States a Building can have
 * Implemented by using the State Design Pattern: [link]
 */
class BuildingState
{
public:
	BuildingState();
	virtual ~BuildingState();

	/**
	* Called whenever a building shoud change states to the Active State
	* The current state of the building decides how and if it obeys this call.
	*/
	virtual void BuildingActive(UBuilding* building) = 0;

	/**
	* Called whenever a building shoud change states to the Inactive State
	* The current state of the building decides how and if it obeys this call.
	*/
	virtual void BuildingInactive(UBuilding* building) = 0;

	/**
	* Called whenever a building shoud change states to the Construction State
	* The current state of the building decides how and if it obeys this call.
	*/
	virtual void BuildingConstruction(UBuilding* building) = 0;

	/**
	* Called whenever a building shoud change states to the Destruction State
	* The current state of the building decides how and if it obeys this call.
	*/
	virtual void BuildingDestruction(UBuilding* building) = 0;

};
#endif