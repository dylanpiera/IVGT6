

#include "ConstructionTimerActor.h"

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
}

// Called every frame
void AConstructionTimerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AConstructionTimerActor::StartConstruction(UBuilding* building, float TimeInHours)
{
	// Check if world is available
	UWorld* World = GetWorld();
	if (World)
	{
		// Set timer
		FTimerHandle ConstructionHandle;
		FTimerDelegate ConstructionDelegate = FTimerDelegate::CreateUObject(this, &AConstructionTimerActor::FinishConstruction, building);
		GetWorldTimerManager().SetTimer(ConstructionHandle, ConstructionDelegate, TimeInHours, false);
	} else
	{
		UE_LOG(LogTemp, Error, TEXT("Construction Timer not in scene. 'UWorld' is NULL."));
	}
}

void AConstructionTimerActor::FinishConstruction(UBuilding* building)
{
	// Warn building the time is over
	building->WhenConstructionFinishes();
}
