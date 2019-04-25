// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingGraphics.h"

// Sets default values
ABuildingGraphics::ABuildingGraphics()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UStaticMeshComponent* Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	RootComponent->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder"));

	
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

