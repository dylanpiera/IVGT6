// Fill out your copyright notice in the Description page of Project Settings.

#include "HexActorGraphics.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"

HexActorGraphics::HexActorGraphics()
{
	// Load hexagon tile mesh and store it
	HexTileMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/Assets/HexTileMesh_StaticMesh.HexTileMesh_StaticMesh'"));

	if (HexTileMesh) {

		// Define mesh size and radius
		MeshSize = HexTileMesh->GetBounds().GetBox().GetSize();
		Radius = HexTileMesh->GetBounds().SphereRadius;
	}
}

// Create a graphic visualization of an hexagon tile for a HexActor 
void HexActorGraphics::CreateHexGraphics(AHexActor* HexActorRef) {
	// If mesh was found apply it to the HexActor 
	if (HexTileMesh)
	{
		// Create mesh and add it to the HexActor
		UStaticMeshComponent* MeshComponent = HexActorRef->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyHexTileMesh"));
		MeshComponent->SetStaticMesh(HexTileMesh);

		// Define HexActor RootComponent as the scene
		USceneComponent* scene;
		scene = HexActorRef->CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
		HexActorRef->SetRootComponent(scene);

		// Attach mesh to the scene
		USceneComponent* HexActorRootComponent = HexActorRef->GetRootComponent();
		MeshComponent->SetupAttachment(HexActorRootComponent);
	}
}

HexActorGraphics::~HexActorGraphics()
{
}

