// Fill out your copyright notice in the Description page of Project Settings.

#include "ConstructionTimerActor.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values
AConstructionTimerActor::AConstructionTimerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AConstructionTimerActor::BeginPlay()
{
	Super::BeginPlay();

	/*
	TArray<AActor*> FoundGameTickManagers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),
		AGameTickManager::StaticClass(),
		FoundGameTickManagers);
	GameTickManager = Cast<AGameTickManager>(FoundGameTickManagers[0]);
	*/
}

// Called every frame
void AConstructionTimerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AConstructionTimerActor::StartConstruction(int TimeInHours)
{
	UE_LOG(LogTemp, Warning, TEXT("Construction starts!"));
	GetWorldTimerManager().SetTimer(
		ConstructionHandle,
		this,
		&AConstructionTimerActor::FinishConstruction,
		5.0f,
		false);
}

void AConstructionTimerActor::FinishConstruction()
{
	UE_LOG(LogTemp, Warning, TEXT("Finishing construction!"));
	GetWorldTimerManager().ClearTimer(ConstructionHandle);
//	OnConstruction.Broadcast();
}

void AConstructionTimerActor::test()
{
	UE_LOG(LogTemp, Warning, TEXT("TESTING construction!"));
	//OnConstruction.BindTo(this, &Building::WhenConstructionFinishes);
	//OnConstruction.AddDynamic(this, &Building::WhenConstructionFinishes);
}