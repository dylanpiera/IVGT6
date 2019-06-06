// Fill out your copyright notice in the Description page of Project Settings.

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

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	Mesh->SetupAttachment(RootComponent);
	growth = 0;
}

// Called when the game starts or when spawned
void ABuildingGraphics::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> FActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),
		ADataHolder::StaticClass(),
		FActors);
	holder = Cast<ADataHolder>(FActors[0]);
	OptionSections building = holder->GetBuilding();

	//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::Printf(TEXT("Selecting building %d"), building));
	
	//SetBuildingGraphics(building, Mesh);
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
	switch (buildingIndex)
	{
		case MineralsBuilding: 
		{
			BuildingMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/Meshes/mineral.mineral'"));
			meshComp->SetStaticMesh(BuildingMesh);
			meshComp->SetWorldScale3D(FVector(50, 50, 0));
			break;
		}
		case EnergyBuilding:
		{
			BuildingMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/Meshes/energy.energy'"));
			meshComp->SetStaticMesh(BuildingMesh);
			meshComp->SetWorldScale3D(FVector(50, 50, 0));
			break;
		}
		case MoneyBuilding:
		{
			BuildingMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/Meshes/house.house'"));
			meshComp->SetStaticMesh(BuildingMesh);
			meshComp->SetWorldScale3D(FVector(50, 50, 0));
			break;
		}
	}
}

void ABuildingGraphics::BuildingAnimation()
{
	if (growth < 50)
	{
		growth += 0.11;
		Mesh->SetWorldScale3D(FVector(50, 50, growth));
	}
}





