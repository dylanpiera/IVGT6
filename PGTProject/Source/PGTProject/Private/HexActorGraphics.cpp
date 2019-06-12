

#include "HexActorGraphics.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "Runtime/Engine/Classes/Materials/Material.h"

HexActorGraphics::HexActorGraphics()
{
	// Load meshes and store them
	_hexTileMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/Assets/HexTile/HexTileMesh_StaticMesh.HexTileMesh_StaticMesh'"));
	_mineralMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/Assets/Resources/MineralRocks.MineralRocks'"));
	
	// Load materials
	_terrainMaterial = LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/Assets/HexTile/TerrainMat.TerrainMat'"));
	_mineralResourceMaterials.insert(pair<EMineralResources, UMaterial*>(EMineralResources::Catanium,
		LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/Assets/Resources/CataniumMat.CataniumMat'"))));
	_mineralResourceMaterials.insert(pair<EMineralResources, UMaterial*>(EMineralResources::NightGems,
		LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/Assets/Resources/NightGemsMat.NightGemsMat'"))));

	UE_LOG(LogTemp, Warning, TEXT("CONSTRUCTOR HEX GRAPHICS"));
	if (_hexTileMesh) {
		UE_LOG(LogTemp, Warning, TEXT("Defining HEX GRAPHICS meshsize radius"));
		// Define hex tile mesh size and radius
		MeshSize = _hexTileMesh->GetBounds().GetBox().GetSize();
		Radius = _hexTileMesh->GetBounds().SphereRadius;
		UE_LOG(LogTemp, Warning, TEXT("meshsize %f %f %f radius %f"), MeshSize.X, MeshSize.Y, MeshSize.Z, Radius);
	}

}

// Create a graphic visualization of an hexagon tile for a HexActor
void HexActorGraphics::CreateHexGraphics(AHexActor* HexActorRef) {
	// If mesh was found apply it to the HexActor 
	if (_hexTileMesh)
	{
		// Add mesh with material to HexActor
		UStaticMeshComponent* MeshComponent = HexActorRef->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyHexTileMesh"));
		MeshComponent->SetStaticMesh(_hexTileMesh);
		MeshComponent->SetMaterial(0, _terrainMaterial);

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
void HexActorGraphics::AddResourceGraphics(EMineralResources resource, AHexActor* HexActorRef)
{
	// If hex and mineral meshes exist, add minerals to the HexActor
	if (_hexTileMesh && _mineralMesh && IfMaterialExists(resource))
	{
		// If resource component does not exist, create one
		UStaticMeshComponent* ResourceMeshComponent = (UStaticMeshComponent*)HexActorRef->GetDefaultSubobjectByName("MyResourceMesh");
		if (ResourceMeshComponent == NULL) {
			ResourceMeshComponent = HexActorRef->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyResourceMesh"));
			// Adjust component position relative to tile mesh
			ResourceMeshComponent->AddRelativeLocation(FVector(113, 100, -13));
			// Define mesh and material
			ResourceMeshComponent->SetStaticMesh(_mineralMesh);
			ResourceMeshComponent->SetMaterial(0, _mineralResourceMaterials.at(resource));
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
			ResourceMeshComponent->SetMaterial(0, _mineralResourceMaterials.at(resource));
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
bool HexActorGraphics::IfMaterialExists(EMineralResources resource)
{
	// If searched for resource material and the list didn't end, material was found
	if (_mineralResourceMaterials.find(resource) != _mineralResourceMaterials.end())
	{
		return true;
	}
	return false;
}

HexActorGraphics::~HexActorGraphics()
{
}

