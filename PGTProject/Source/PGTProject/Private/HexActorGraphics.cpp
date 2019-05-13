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

	scene = NULL; // Reset scene
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

		// Define HexActor RootComponent as the scene
		if (scene == NULL) {
			scene = HexActorRef->CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
			HexActorRef->SetRootComponent(scene);
		}

		// Attach mesh to the scene
		USceneComponent* HexActorRootComponent = HexActorRef->GetRootComponent();
		MeshComponent->SetupAttachment(HexActorRootComponent);
	}
}

void HexActorGraphics::AddResourceGraphics(MineralResources resource, AHexActor* HexActorRef)
{
	// If hex and mineral meshes exist, add minerals to the HexActor
	if (HexTileMesh && MineralMesh && IfMaterialExists(resource))
	{
		// Add mesh with material to HexActor
		UStaticMeshComponent* ResourceMeshComponent = HexActorRef->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyResourceMesh"));
		ResourceMeshComponent->SetStaticMesh(MineralMesh);
		ResourceMeshComponent->SetMaterial(0, MineralResourceMaterials.at(resource));

		// Define HexActor RootComponent as the scene
		if (scene == NULL) {
			scene = HexActorRef->CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
			HexActorRef->SetRootComponent(scene);
		}

		// Attach resource mesh to the scene
		USceneComponent* HexActorRootComponent = HexActorRef->GetRootComponent();
		ResourceMeshComponent->SetupAttachment(HexActorRootComponent);
	}
}

// Check if material exists
bool HexActorGraphics::IfMaterialExists(MineralResources resource)
{
	// If searched for resource material and the list didn't end, then found it
	if (MineralResourceMaterials.find(resource) != MineralResourceMaterials.end())
	{
		return true;
	}
	return false;
}

HexActorGraphics::~HexActorGraphics()
{
}

