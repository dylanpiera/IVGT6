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

	/**
	 * @brief Mesh storage
	 * 
	 */
	UStaticMesh* _hexTileMesh;		

	/**
	 * @brief Terrain Material
	 * 
	 */
	UMaterial* _terrainMaterial;

	/**
	 * @brief Minerals Mesh storage
	 * 
	 */
	UStaticMesh* _mineralMesh;

	/**
	 * @brief Store resources materials
	 * 
	 */
	map<EMineralResources, UMaterial*> _mineralResourceMaterials;

	// Check if material exists
	bool IfMaterialExists(EMineralResources resource);

public:
	FVector MeshSize;				// Mesh size
	float Radius;					// Mesh sphere radius

	/**
	 * @brief Construct a new Hex Actor Graphics object
	 * 
	 */
	HexActorGraphics();
	
	/**
	 * @brief Destroy the Hex Actor Graphics object
	 * 
	 */
	~HexActorGraphics();

	/**
	 * @brief Create a graphic visualization of an hexagon tile for a HexActor
	 * 
	 * @param HexActorRef 
	 */
	void CreateHexGraphics(AHexActor* HexActorRef);

	/**
	 * @brief Create a graphic visualization of the resources for a HexActor
	 * 
	 * @param resource 
	 * @param HexActorRef 
	 */
	void AddResourceGraphics(EMineralResources resource, AHexActor* HexActorRef);

	
	/**
	 * @brief Remove graphic visualization of resources from HexActor
	 * 
	 * @param HexActorRef 
	 */
	void RemoveResourceGraphics(AHexActor* HexActorRef);
};
