#include "Building.h"
#include "ConstructionTimerActor.h"
#include "BuildingGraphics.h"
#include "ConstructionState.h"
#include "ActiveState.h"

// Constructor
UBuilding::UBuilding()
{
	// Set total construction time
	_timeInHours = 5.0f;
	// Find construction timer
	GetConstructionTimer();	
	// Set initial construction state
	SetState(new ConstructionState());
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
	SetState(new ActiveState());
	// Spawn building
	CreateBuilding();
}

void UBuilding::BuildingConstruction(FVector location, FRotator rotation, FActorSpawnParameters spawnInfo)
{
	// Set graphics info
	_location = FVector(location.X, location.Y, location.Z);
	_rotation = rotation;
	_spawnInfo = spawnInfo;

	// Start timer
	_constructionTimer->StartConstruction(this, _timeInHours);
}

void UBuilding::CreateBuilding() {
	// Create building mesh
	_buildingGraphics = GWorld->SpawnActor<ABuildingGraphics>(ABuildingGraphics::StaticClass(), _location, _rotation, _spawnInfo);
}

void UBuilding::BuildingFunction(Resources &resource)
{
	resource._money -= 100;
}

void UBuilding::BuildingActive(Resources &resource, Resources &maintenance)
{
	BuildingFunction(resource);
	BuildingUpkeep(maintenance);
}

void UBuilding::BuildingUpkeep(Resources &resource)
{
}

void UBuilding::BuildingInactive()
{
}

void UBuilding::BuildingDestruction()
{
}

void UBuilding::SetState(BuildingState * state)
{
	_bState = state;
}

BuildingState * UBuilding::GetState()
{
	return _bState;
}
