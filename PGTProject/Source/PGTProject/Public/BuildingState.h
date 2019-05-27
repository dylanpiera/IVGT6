// Fill out your copyright notice in the Description page of Project Settings.

#ifndef BuildingState_Header
#define BuildingState_Header
#include "BuildingObject.h"
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
	virtual void BuildingActive(BuildingObject* building) = 0;

	/**
	* Called whenever a building shoud change states to the Inactive State
	* The current state of the building decides how and if it obeys this call.
	*/
	virtual void BuildingInactive(BuildingObject* building) = 0;

	/**
	* Called whenever a building shoud change states to the Construction State
	* The current state of the building decides how and if it obeys this call.
	*/
	virtual void BuildingConstruction(BuildingObject* building) = 0;

	/**
	* Called whenever a building shoud change states to the Destruction State
	* The current state of the building decides how and if it obeys this call.
	*/
	virtual void BuildingDestruction(BuildingObject* building) = 0;

};
#endif