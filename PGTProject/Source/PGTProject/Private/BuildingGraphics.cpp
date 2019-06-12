

#include "BuildingGraphics.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Building.h"
#include "Engine/Engine.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"

// Sets default values
ABuildingGraphics::ABuildingGraphics()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Instantiate the static mesh and set as RootComponent
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	Mesh->SetupAttachment(RootComponent);

	//initialize growth variable for animation.
	growth = 0;
}

// Called when the game starts or when spawned
void ABuildingGraphics::BeginPlay()
{
	Super::BeginPlay();

	// Finds the actor ADataHolder in the gameworld.
	TArray<AActor*> FActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),
		ADataHolder::StaticClass(),
		FActors);
	holder = Cast<ADataHolder>(FActors[0]);
	OptionSections building = holder->GetBuilding();
}

void ABuildingGraphics::LoadGraphics(OptionSections buildingIndex) 
{
	SetBuildingGraphics(buildingIndex, Mesh);
}


// Called every frame
void ABuildingGraphics::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	BuildingAnimation();
}

void ABuildingGraphics::SetBuildingGraphics(OptionSections buildingIndex, UStaticMeshComponent* meshComp)
{
	//BADSMELL: Code Duplication! I can "Extract Method" here.
	switch (buildingIndex)
	{
		case MineralsBuilding: 
		{
			// Loads the proper mesh for the specific building type.
			SetGraphic(TEXT("StaticMesh'/Game/Meshes/mineral.mineral'"));
		}
		case EnergyBuilding:
		{
			// Loads the proper mesh for the specific building type.
			SetGraphic(TEXT("StaticMesh'/Game/Meshes/energy.energy'"));
		}
		case MoneyBuilding:
		{
			// Loads the proper mesh for the specific building type.
			SetGraphic(TEXT("StaticMesh'/Game/Meshes/house.house'"));
			break;
		}
		case FoodBuilding:
		{
			// Loads the proper mesh for the specific building type.
			SetGraphic(TEXT("StaticMesh'/Game/Meshes/Cone.Cone'"));
		}
	}
}

// filePath should be TEXT("filepathstring")
void ABuildingGraphics::SetGraphic(const TCHAR* filePath)
{
	BuildingMesh = LoadObject<UStaticMesh>(nullptr, filePath);
	Mesh->SetStaticMesh(BuildingMesh);
	Mesh->SetWorldScale3D(FVector(45, 45, 0));
}

void ABuildingGraphics::BuildingAnimation()
{
	// Hardcoded testing. this looked best ingame.
	if (growth < 45)
	{
		growth += 0.16;
		Mesh->SetWorldScale3D(FVector(45, 45, growth));
	}
}





