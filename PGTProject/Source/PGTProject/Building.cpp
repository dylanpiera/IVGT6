#include "Building.h"
#include "Engine/World.h"
#include "ConstructionTimerActor.h"

// Constructor
Building::Building()
{
	GetConstructionTimer();
	
	//_constructionTimer->OnConstruction.AddDynamic(this, &Building::WhenConstructionFinishes);
}

void Building::GetConstructionTimer() {
	// Find ConstructionTimerActor instance
	TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(GWorld,
			AConstructionTimerActor::StaticClass(),
			FoundActors);
	// If
	if(FoundActors.Num() == 1) {
		_constructionTimer = Cast<AConstructionTimerActor>(FoundActors[0]);
	} else {
		UE_LOG(LogTemp, Error, TEXT("Number of ConstructionTimerActors inconsistent on Building."));
	}
}

Building::~Building()
{
}

void Building::WhenConstructionFinishes()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Construction finished! AAA"));
}

void Building::BeginConstruction(int TimeInHours)
{
	_constructionTimer->StartConstruction(this, TimeInHours);
}

