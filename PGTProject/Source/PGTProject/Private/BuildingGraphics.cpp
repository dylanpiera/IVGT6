// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingGraphics.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "WidgetBlueprintLibrary.h"

// Sets default values
ABuildingGraphics::ABuildingGraphics()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*UStaticMeshComponent* Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	Mesh->SetupAttachment(RootComponent);

	BuildingMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/Meshes/mineral.mineral'"));

	Mesh->SetStaticMesh(BuildingMesh);
	Mesh->SetWorldScale3D(FVector(50, 50, 50));*/
	
	//ToolbarGraphics* ToolGraphs;
	//TSharedPtr<ToolbarGraphics> ToolBar;
	//SetBuildingGraphics();

	TArray<UUserWidget*> FoundWidgets;
	UWidgetBlueprintLibrary::GetAllWidgetsOfClass(GetWorld(), &FoundWidgets, );
	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),
		//AEconomyManager::StaticClass(),
		FoundActors);

}

// Called when the game starts or when spawned
void ABuildingGraphics::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABuildingGraphics::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuildingGraphics::SetBuildingGraphics(OptionSections building)
{
	switch (building)
	{
		case MineralsBuilding: 
		{
			UStaticMeshComponent* Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
			Mesh->SetupAttachment(RootComponent);
			BuildingMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/Meshes/mineral.mineral'"));
			Mesh->SetStaticMesh(BuildingMesh);
			Mesh->SetWorldScale3D(FVector(50, 50, 50));
			}
		case EnergyBuilding:
		{
			UStaticMeshComponent* Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
			Mesh->SetupAttachment(RootComponent);
			BuildingMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/Meshes/energy.energy'"));
			Mesh->SetStaticMesh(BuildingMesh);
			Mesh->SetWorldScale3D(FVector(50, 50, 50));
			}
		case MoneyBuilding:
		{
			UStaticMeshComponent* Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
			Mesh->SetupAttachment(RootComponent);
			BuildingMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/Meshes/house.house'"));
			Mesh->SetStaticMesh(BuildingMesh);
			Mesh->SetWorldScale3D(FVector(50, 50, 50));
		}
	}
}





