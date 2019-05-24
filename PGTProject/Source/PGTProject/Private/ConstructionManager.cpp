// Fill out your copyright notice in the Description page of Project Settings.

#include "ConstructionManager.h"

// Sets default values
AConstructionManager::AConstructionManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AConstructionManager::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),
		AConstructionTimerActor::StaticClass(),
		FoundActors);
	_mainConstructionTimer = Cast<AConstructionTimerActor>(FoundActors[0]);
}

// Called every frame
void AConstructionManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

