//#ifndef BuildingObject_Header
//#define BuildingObject_Header
#pragma once
#include "Resources.h"
#include "Runtime/Core/Public/Math/Vector.h"
#include "Engine/World.h"
#include "UObject/NoExportTypes.h"
#include "Building.generated.h"

class AConstructionTimerActor;
class ABuildingGraphics;
class BuildingState;

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

	// Current construction phase to control building functionality
	BuildingState *_bState;
protected:
	// Total time to construct the building
	float _timeInHours;
public:
	UBuilding();
	virtual ~UBuilding();

	// Create building graphics
	void CreateBuilding();

	// Start construction timer
	void BuildingConstruction(FVector location, FRotator rotation, FActorSpawnParameters spawnInfo);

	// Function called when time is over
	void WhenConstructionFinishes();

	/*
	 * override this and implement what the building needs to update
	*/
	virtual void BuildingActive(Resources &resource, Resources &maintenance);

	
	virtual void BuildingFunction(Resources &resource);

	/**
	 *
	*/
	virtual void BuildingUpkeep(Resources &resource);

	/**
	 *
	*/
	virtual void BuildingInactive();

	/**
	 *
	*/
	virtual void BuildingDestruction();

	/**
	 *
	*/
	void SetState(BuildingState* state);

	/**
	 *
	*/
	BuildingState* GetState();


};
//#endif