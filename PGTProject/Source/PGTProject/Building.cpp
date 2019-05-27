#include "Building.h"
#include "ConstructionTimerActor.h"
#include "BuildingGraphics.h"

// Constructor
UBuilding::UBuilding()
{
	// Set total construction time
	_timeInHours = 5.0f;
	// Find construction timer
	GetConstructionTimer();	
	// Set initial construction state
	_constructionState = EConstructionState::Created;
}

void UBuilding::GetConstructionTimer() {
	// Find ConstructionTimerActor instance
	TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(GWorld,
			AConstructionTimerActor::StaticClass(),
			FoundActors);
	// Check number of instances for construction timer
	if(FoundActors.Num() == 1) {
		_constructionTimer = Cast<AConstructionTimerActor>(FoundActors[0]);
	} else {
		UE_LOG(LogTemp, Error, TEXT("Number of ConstructionTimerActors inconsistent on Building."));
	}
}

UBuilding::~UBuilding()
{
}

void UBuilding::WhenConstructionFinishes()
{
	// Change construction state
	_constructionState = EConstructionState::Done;
	// Spawn building
	CreateBuilding();
}

void UBuilding::BeginConstruction(FVector location, FRotator rotation, FActorSpawnParameters spawnInfo)
{
	// Set graphics info
	_location = FVector(location.X, location.Y, location.Z);
	_rotation = rotation;
	_spawnInfo = spawnInfo;

	// Change construction state
	_constructionState = EConstructionState::Constructing;
	_constructionTimer->StartConstruction(this, _timeInHours);
}

void UBuilding::CreateBuilding() {
	// Create building mesh
	_buildingGraphics = GWorld->SpawnActor<ABuildingGraphics>(ABuildingGraphics::StaticClass(), _location, _rotation, _spawnInfo);
}