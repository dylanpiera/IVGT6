// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingConstructionTimer.h"
#include "MineralBuilding.h"
#include "ConstructionTimerActor.h"

// Sets default values
ATestingConstructionTimer::ATestingConstructionTimer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestingConstructionTimer::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("New building!"));
	MineralBuilding a;
	UE_LOG(LogTemp, Warning, TEXT("Ask for construction."));
	a.BeginConstruction(5);
}

// Called every frame
void ATestingConstructionTimer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

