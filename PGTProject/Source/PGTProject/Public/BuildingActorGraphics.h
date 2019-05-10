// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"

class PGTPROJECT_API BuildingActorGraphics
{
private:
	UStaticMesh* BuildingMesh;
	UMaterial* BuildingMaterial;

public:
	FVector MeshSize;
	float Radius;

	BuildingActorGraphics();
	~BuildingActorGraphics();

	//void CreateBuildingGraphics();
};
