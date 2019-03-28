// Fill out your copyright notice in the Description page of Project Settings.

#include "HexActorGraphics.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"

HexActorGraphics::HexActorGraphics()
{
}

// Create a graphic visualization of an hexagon tile for a HexActor 
void HexActorGraphics::CreateHexGraphics(AHexActor* HexActorRef) {
	// Get hexagon tile mesh
//	static ConstructorHelpers::FObjectFinder<UStaticMesh> HexTileMeshAsset(TEXT("StaticMesh'/Game/Assets/HexTileMesh_StaticMesh.HexTileMesh_StaticMesh'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> HexTileMeshAsset(TEXT("StaticMesh'/Game/Assets/BlueHexTile_StaticMesh.BlueHexTile_StaticMesh'"));
	// If mesh was found apply it to the HexActor 
	if (HexTileMeshAsset.Object)
	{
		// Create mesh and add it to the HexActor
		UStaticMeshComponent* MeshComponent = HexActorRef->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyHexTileMesh"));
		MeshComponent->SetStaticMesh(HexTileMeshAsset.Object);

		// Define HexActor RootComponent as the scene
		USceneComponent* scene;
		scene = HexActorRef->CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
		HexActorRef->SetRootComponent(scene);

		// Attach mesh to the scene
		USceneComponent* HexActorRootComponent = HexActorRef->GetRootComponent();
		MeshComponent->SetupAttachment(HexActorRootComponent);
	}
}

void HexActorGraphics::GetHeight() {
	// Get hexagon tile mesh
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> HexTileMeshAsset(TEXT("StaticMesh'/Game/Assets/HexTileMesh_StaticMesh.HexTileMesh_StaticMesh'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> HexTileMeshAsset(TEXT("StaticMesh'/Game/Assets/BlueHexTile_StaticMesh.BlueHexTile_StaticMesh'"));

	UStaticMesh* m = HexTileMeshAsset.Object;
	MeshSize = m->GetBounds().GetBox().GetSize();
	Radius = m->GetBounds().SphereRadius;
	UE_LOG(LogTemp, Warning, TEXT("radius = %f"), Radius);
}

HexActorGraphics::~HexActorGraphics()
{
}

