#include "Building.h"
#include "ConstructionTimerActor.h"
#include "BuildingGraphics.h"
#include "EconomyManager.h"
#include "ConstructionState.h"
#include "ActiveState.h"

// Constructor
UBuilding::UBuilding()
{
	int32 y = 0;
	x = &y;
	// Set total construction time
	_timeInHours = 5.0f;
	// Find construction timer
	GetConstructionTimer();	
	// Set initial construction state
	SetState(new ConstructionState());
	_buildingType = MineralsBuilding;
	
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
		UE_LOG(LogTemp, Warning, TEXT("Number of ConstructionTimerActors inconsistent on Building."));
	}
}

UBuilding::~UBuilding()
{
}

void UBuilding::WhenConstructionFinishes()
{
	*x = *x + 1;
	// Spawn building
	CreateBuilding();
	// Change construction state
	SetState(new ActiveState());
	
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
	_buildingGraphics->LoadGraphics(_buildingType);
}

void UBuilding::SetMesh(OptionSections option) {
	_buildingType = option;
}

void UBuilding::BuildingFunction(Resources &resource){}

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
