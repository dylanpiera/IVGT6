#pragma once

#include "CoreMinimal.h"
#include "HexActor.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "map"
#include "Constants.h"

using namespace std;

/**
 * @class HexActorGraphics
 * @brief Creates a graphic representation for a hexagonal tile.
 * 
 */
class PGTPROJECT_API HexActorGraphics
{
private:

	/**
	 * @brief Store hexagonal tile static mesh
	 * 
	 */
	UStaticMesh* _hexTileMesh;		

	/**
	 * @brief Store terrain material
	 * 
	 */
	UMaterial* _terrainMaterial;

	/**
	 * @brief Store minerals resource static mesh
	 * 
	 */
	UStaticMesh* _mineralMesh;

	/**
	 * @brief Store all resources materials
	 * 
	 */
	map<EMineralResources, UMaterial*> _mineralResourceMaterials;

	/**
	 * @brief Check if resource has a linked material to represent the resource
	 * 
	 * @param resource 
	 */
	bool IfMaterialExists(EMineralResources resource);

public:
	FVector MeshSize;				// Mesh size
	float Radius;					// Mesh sphere radius

	/**
	 * @brief Get all meshes and materials needed in the project, and store references to them.
	 * 
	 */
	HexActorGraphics();
	
	/**
	 * @brief Default destructor
	 * 
	 */
	~HexActorGraphics();

	/**
	 * @brief Attach hexagonal mesh to AHexActor and apply terrain material to mesh.
	 * 
	 * @param HexActorRef 
	 */
	void CreateHexGraphics(AHexActor* HexActorRef);

	/**
	 * @brief Attach resource mesh to AHexActor and apply resource material.
	 * 
	 * @param resource 
	 * @param HexActorRef 
	 */
	void AddResourceGraphics(EMineralResources resource, AHexActor* HexActorRef);

	
	/**
	 * @brief Remove resource graphics from AHexActor
	 * 
	 * @param HexActorRef 
	 */
	void RemoveResourceGraphics(AHexActor* HexActorRef);
};
