// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HexActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

class PGTPROJECT_API HexActorGraphics
{
public:
	FVector MeshSize;

	// Create a graphic visualization of an hexagon tile for a HexActor 
	void CreateHexGraphics(AHexActor* HexActorRef);
	void GetHeight();

	HexActorGraphics();		// Constructor
	~HexActorGraphics();	// Destructor
};
