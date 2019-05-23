// Fill out your copyright notice in the Description page of Project Settings.

#ifndef BuildingState_Header
#define BuildingState_Header
#include "BuildingObject.h"
#include <typeinfo>
#include "CoreMinimal.h"

/**
 * 
 */
class BuildingState
{
public:
	BuildingState();
	virtual ~BuildingState();

	/**
	*
	*/
	virtual void BuildingActive(BuildingObject* building) = 0;

	/**
	*
	*/
	virtual void BuildingInactive(BuildingObject* building) = 0;

	/**
	 *
	*/
	virtual void BuildingConstruction(BuildingObject* building) = 0;

	/**
	*
	*/
	virtual void BuildingDestruction(BuildingObject* building) = 0;

};
#endif