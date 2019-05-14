// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HexActor.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "map"

using namespace std;

// Avaiable resources
enum MineralResources { Catanium, NightGems };

class PGTPROJECT_API HexActorGraphics
{
private:
	UStaticMesh* HexTileMesh;		// Mesh storage
	UMaterial* TerrainMaterial;		// Terrain Material

	UStaticMesh* MineralMesh;		// Minerals Mesh storage
	map<MineralResources, UMaterial*> MineralResourceMaterials; // Store resources materials

	// Check if material exists
	bool IfMaterialExists(MineralResources resource);

public:
	FVector MeshSize;				// Mesh size
	float Radius;					// Mesh sphere radius

	HexActorGraphics();				// Constructor
	~HexActorGraphics();			// Destructor

	// Create a graphic visualization of an hexagon tile for a HexActor 
	void CreateHexGraphics(AHexActor* HexActorRef);
	// Create a graphic visualization of the resources for a HexActor
	void AddResourceGraphics(MineralResources resource, AHexActor* HexActorRef);
	// Remove graphic visualization of resources from HexActor
	void RemoveResourceGraphics(AHexActor* HexActorRef);
};
