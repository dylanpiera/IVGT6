// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HexActor.h"

/**
 * 
 */
class PGTPROJECT_API HexActorGraphics
{
public:
	// Create a graphic visualization of an hexagon tile for a HexActor 
	void CreateHexGraphics(AHexActor* A);

	HexActorGraphics();		// Constructor
	~HexActorGraphics();	// Destructor
};
