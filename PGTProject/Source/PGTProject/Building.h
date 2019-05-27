#pragma once
#include "Resources.h"
#include "Constants.h"
#include "Runtime/Core/Public/Math/Vector.h"
#include "Engine/World.h"
#include "UObject/NoExportTypes.h"
#include "Building.generated.h"

class AConstructionTimerActor;
class ABuildingGraphics;

UCLASS()
class PGTPROJECT_API UBuilding : public UObject {
	GENERATED_BODY()
private:
	// Graphics info
	ABuildingGraphics* _buildingGraphics;
	FVector _location;
	FRotator _rotation;
	FActorSpawnParameters _spawnInfo;

	// Construction Timer
	AConstructionTimerActor* _constructionTimer;
	void GetConstructionTimer();

protected:
	// Current construction phase to control building functionality
	EConstructionState _constructionState;
	// Total time to construct the building
	float _timeInHours;
public:
	UBuilding();
	virtual ~UBuilding();

	/*
	 * override this and implement what the building needs to update
	*/
	virtual void BuildingFunction(Resources& resource) { 
		// Block building from producing while it's not done constructing
		if(_constructionState == EConstructionState::Done) {
			resource._money -= 100;
		}
	}

	// Create building graphics
	void CreateBuilding();

	// Start construction timer
	void BeginConstruction(FVector location, FRotator rotation, FActorSpawnParameters spawnInfo);

	// Function called when time is over
	void WhenConstructionFinishes();
};