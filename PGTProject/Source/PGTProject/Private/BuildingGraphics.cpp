// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingGraphics.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Building.h"

// Sets default values
ABuildingGraphics::ABuildingGraphics()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UStaticMeshComponent* Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	Mesh->SetupAttachment(RootComponent);

	BuildingMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/Assets/Cube.Cube'"));
	BuildingMaterial = LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/Assets/Lambert1.Lambert1'"));

	Mesh->SetStaticMesh(BuildingMesh);
	Mesh->SetMaterial(0, BuildingMaterial);

	/*TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),
		AEconomyManager::StaticClass(),
		FoundActors);
	EcoMan = Cast<AEconomyManager>(FoundActors[0]);*/

	//EcoMan->ActiveBuildings.Add(dynamic_cast<>(new MineralBuilding()));
	
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

