// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HexActor.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "map"
#include "Constants.h"

using namespace std;

class PGTPROJECT_API HexActorGraphics
{
private:
	UStaticMesh* _hexTileMesh;		// Mesh storage
	UMaterial* _terrainMaterial;		// Terrain Material

	UStaticMesh* _mineralMesh;		// Minerals Mesh storage
	map<EMineralResources, UMaterial*> _mineralResourceMaterials; // Store resources materials

	// Check if material exists
	bool IfMaterialExists(EMineralResources resource);

public:
	FVector MeshSize;				// Mesh size
	float Radius;					// Mesh sphere radius

	HexActorGraphics();				// Constructor
	~HexActorGraphics();			// Destructor

	// Create a graphic visualization of an hexagon tile for a HexActor 
	void CreateHexGraphics(AHexActor* HexActorRef);
	// Create a graphic visualization of the resources for a HexActor
	void AddResourceGraphics(EMineralResources resource, AHexActor* HexActorRef);
	// Remove graphic visualization of resources from HexActor
	void RemoveResourceGraphics(AHexActor* HexActorRef);
};
