#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"

/**
 * @brief 
 * 
 */
class PGTPROJECT_API BuildingActorGraphics
{
private:

	UStaticMesh* BuildingMesh;

	UMaterial* BuildingMaterial;

public:
	FVector MeshSize;
	float Radius;

	/**
	 * @brief 
	 * 
	 */
	BuildingActorGraphics();
	~BuildingActorGraphics();

	//void CreateBuildingGraphics();
};
