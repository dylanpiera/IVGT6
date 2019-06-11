//#ifndef BuildingObject_Header
//#define BuildingObject_Header
#pragma once
#include "Resources.h"
#include "Constants.h"
#include "Runtime/Core/Public/Math/Vector.h"
#include "Engine/World.h"
#include "UObject/NoExportTypes.h"
#include "Building.generated.h"

class AConstructionTimerActor;

class ABuildingGraphics;

class BuildingState;

UCLASS()
/**
 * @class Building
 * @brief Base Class for all building types. Multiple buildings can be created.
 * Needs to be a UCLASS to work with ConstructionTimer.
 * 
 */
class PGTPROJECT_API UBuilding : public UObject {
	GENERATED_BODY()
private:
	/**
	 * @brief Reference to graphic representation
	 */
	ABuildingGraphics* _buildingGraphics;
	/**
	 * @brief Store information to spawn building graphics
	 */
	FVector _location;
	FRotator _rotation;
	FActorSpawnParameters _spawnInfo;
	/**
	 * @brief Building type
	 */
	OptionSections _buildingType;

	/**
	 * @brief Reference to AConstructionTimerActor
	 */
	AConstructionTimerActor* _constructionTimer;
	/**
	 * @brief Get reference to a AConstructionTimerActor in the world
	 * 
	 */
	void GetConstructionTimer();

	/**
	 * @brief Current construction phase to control building functionality
	 */
	BuildingState *_bState;
protected:
	/**
	 * @brief Total time to construct the building
	 */
	float _timeInHours;
	/**
	 * @brief Financial cost to create this building
	 */
	int _buildingCost;
public:
	/**
	 * @brief Construct a new building.
	 * Set AConstructionTimerActor reference, building cost, total construction time, and initial construction state.
	 * 
	 */
	UBuilding();
	/**
	 * @brief Default destructor
	 * 
	 */
	virtual ~UBuilding();

	int32* x;

	/**
	 * @brief Set building financial cost
	 * 
	 */
	virtual void SetBuildingCost();

	/**
	 * @brief Create building graphical representation.
	 * 
	 */
	void CreateBuilding();

	/**
	 * @brief Sets basic information for spawning the building, and starts building construction.
	 * 
	 * @param location 
	 * @param rotation 
	 * @param spawnInfo 
	 */
	void BuildingConstruction(FVector location, FRotator rotation, FActorSpawnParameters spawnInfo);

	/**
	 * @brief Update construction state for building and update total amount of buildings.
	 * 
	 */
	void WhenConstructionFinishes();

	/**
	 * @brief Runs both BuildingFunction and BuildingUpkeep
	 * 
	 * @param resource 
	 * @param maintenance 
	 */
	virtual void BuildingActive(Resources &resource, Resources &maintenance);

	/**
	 * @brief Override to implement building production of choice. 
	 * 
	 * @param resource 
	 */
	virtual void BuildingFunction(Resources &resource);

	/**
	 * @brief Override to implement building upkeep of choice
	 * 
	 * @param resource 
	 */
	virtual void BuildingUpkeep(Resources &resource);

	/**
	 * @brief Override to implement function of choice while Inactive
	 * 
	 */
	virtual void BuildingInactive();

	/**
	 * @brief Override to implement function of choice when building is destroyed
	 * 
	 */
	virtual void BuildingDestruction();

	/**
	 * @brief Set building construction state
	 * 
	 * @param state 
	 */
	void SetState(BuildingState* state);

	/**
	 * @brief Set building type to define building mesh
	 * 
	 * @param option 
	 */
	void SetMesh(OptionSections option);

	/**
	 * @brief Get building construction state
	 * 
	 * @return BuildingState* 
	 */
	BuildingState* GetState();

	/**
	 * @brief Get building cost
	 * 
	 * @return int 
	 */
	int GetCost() { return _buildingCost; }
};
//#endif