// Fill out your copyright notice in the Description page of Project Settings.

#include "HexActorGraphics.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "Runtime/Engine/Classes/Materials/Material.h"

HexActorGraphics::HexActorGraphics()
{
	// Load meshes and store them
	HexTileMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/Assets/HexTile/HexTileMesh_StaticMesh.HexTileMesh_StaticMesh'"));
	MineralMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/Assets/Resources/MineralRocks.MineralRocks'"));
	
	// Load materials
	TerrainMaterial = LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/Assets/HexTile/TerrainMat.TerrainMat'"));
	MineralResourceMaterials.insert(pair<MineralResources, UMaterial*>(Catanium,
		LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/Assets/Resources/CataniumMat.CataniumMat'"))));
	MineralResourceMaterials.insert(pair<MineralResources, UMaterial*>(NightGems,
		LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/Assets/Resources/NightGemsMat.NightGemsMat'"))));

	if (HexTileMesh) {
		// Define hex tile mesh size and radius
		MeshSize = HexTileMesh->GetBounds().GetBox().GetSize();
		Radius = HexTileMesh->GetBounds().SphereRadius;
	}

}

// Create a graphic visualization of an hexagon tile for a HexActor
void HexActorGraphics::CreateHexGraphics(AHexActor* HexActorRef) {
	// If mesh was found apply it to the HexActor 
	if (HexTileMesh)
	{
		// Add mesh with material to HexActor
		UStaticMeshComponent* MeshComponent = HexActorRef->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyHexTileMesh"));
		MeshComponent->SetStaticMesh(HexTileMesh);
		MeshComponent->SetMaterial(0, TerrainMaterial);

		// If HexActor doesn't have RootComponent, create it
		if (HexActorRef->GetRootComponent() == NULL) {
			USceneComponent* scene = HexActorRef->CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
			HexActorRef->SetRootComponent(scene);
		}

		// Attach mesh to the scene
		USceneComponent* HexActorRootComponent = HexActorRef->GetRootComponent();
		MeshComponent->SetupAttachment(HexActorRootComponent);
	}
}

// Create a graphic visualization of the resources for a HexActor
void HexActorGraphics::AddResourceGraphics(MineralResources resource, AHexActor* HexActorRef)
{
	// If hex and mineral meshes exist, add minerals to the HexActor
	if (HexTileMesh && MineralMesh && IfMaterialExists(resource))
	{
		// If resource component does not exist, create one
		UStaticMeshComponent* ResourceMeshComponent = (UStaticMeshComponent*)HexActorRef->GetDefaultSubobjectByName("MyResourceMesh");
		if (ResourceMeshComponent == NULL) {
			ResourceMeshComponent = HexActorRef->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyResourceMesh"));
			// Adjust component position relative to tile mesh
			ResourceMeshComponent->AddRelativeLocation(FVector(113, 100, -13));
			// Define mesh and material
			ResourceMeshComponent->SetStaticMesh(MineralMesh);
			ResourceMeshComponent->SetMaterial(0, MineralResourceMaterials.at(resource));
			// Register component
			ResourceMeshComponent->RegisterComponent();

			// If HexActor doesn't have RootComponent, create it
			if (HexActorRef->GetRootComponent() == NULL) {
				USceneComponent* scene = HexActorRef->CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
				HexActorRef->SetRootComponent(scene);
			}

			// Attach resource mesh to the scene
			USceneComponent* HexActorRootComponent = HexActorRef->GetRootComponent();
			ResourceMeshComponent->AttachToComponent(HexActorRootComponent, FAttachmentTransformRules::KeepRelativeTransform);
		}
		else // If resource component exists update it
		{
			// Redefine material
			ResourceMeshComponent->SetMaterial(0, MineralResourceMaterials.at(resource));
			// Register component
			ResourceMeshComponent->RegisterComponent();
		}
	}
}

// Remove graphic visualization of resources from HexActor
void HexActorGraphics::RemoveResourceGraphics(AHexActor* HexActorRef)
{
	UStaticMeshComponent* ResourceComponent = (UStaticMeshComponent*) HexActorRef->GetDefaultSubobjectByName("MyResourceMesh");
	ResourceComponent->UnregisterComponent();
}

// Check if material exists
bool HexActorGraphics::IfMaterialExists(MineralResources resource)
{
	// If searched for resource material and the list didn't end, material was found
	if (MineralResourceMaterials.find(resource) != MineralResourceMaterials.end())
	{
		return true;
	}
	return false;
}

HexActorGraphics::~HexActorGraphics()
{
}

