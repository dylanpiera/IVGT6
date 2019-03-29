// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HexActor.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"

class PGTPROJECT_API HexActorGraphics
{
private:
	UStaticMesh* HexTileMesh;	// Mesh storage

public:
	FVector MeshSize;			// Mesh size
	float Radius;				// Mesh sphere radius

	HexActorGraphics();			// Constructor
	~HexActorGraphics();		// Destructor

	// Create a graphic visualization of an hexagon tile for a HexActor 
	void CreateHexGraphics(AHexActor* HexActorRef);
};
