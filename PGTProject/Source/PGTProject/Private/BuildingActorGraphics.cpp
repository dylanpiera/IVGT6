// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingActorGraphics.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "Runtime/Engine/Classes/Materials/Material.h"

BuildingActorGraphics::BuildingActorGraphics()
{
	// Load building mesh and store it
	BuildingMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/Assets/HexTileMesh_StaticMesh.HexTileMesh_StaticMesh'"));
	BuildingMaterial = LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/Assets/HexTile_Materials/RockSnow_Material.RockSnow_Material'"));
	
	if (BuildingMesh)
	{
		// Define mesh size and radius
		MeshSize = BuildingMesh->GetBounds().GetBox().GetSize();
		Radius = BuildingMesh->GetBounds().SphereRadius;
	}
}

void BuildingActorGraphics::CreateBuildingGraphics(ABuildingActor* BuildingActor)
{
	// Create mesh with material on BuildingActor
	UStaticMeshComponent* MeshComponent = BuildingActor->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyHexTileMesh"));
	MeshComponent->SetStaticMesh(BuildingMesh);
	MeshComponent->SetMaterial(0, BuildingMaterial);

	// Define BuildingActor RootComponent as the scene
	USceneComponent* scene;
	scene = BuildingActor->CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	BuildingActor->SetRootComponent(scene);

	// Attach mesh to the scene
	USceneComponent* BuildingActorRootComponent = BuildingActor->GetRootComponent();
	MeshComponent->SetupAttachment(BuildingActorRootComponent);
}

BuildingActorGraphics::~BuildingActorGraphics()
{
}
