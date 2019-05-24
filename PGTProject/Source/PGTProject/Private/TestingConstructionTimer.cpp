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

	MineralBuilding a;
	a.BeginConstruction(5);

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GWorld,
		AConstructionTimerActor::StaticClass(),
		FoundActors);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Number of actors: %d"), FoundActors.Num()));
}

// Called every frame
void ATestingConstructionTimer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

