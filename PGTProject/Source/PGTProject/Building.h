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
 * @brief Base Class for all building types. 
 * 
 */
class PGTPROJECT_API UBuilding : public UObject {
	GENERATED_BODY()
private:
	// Graphics info
	ABuildingGraphics* _buildingGraphics;
	FVector _location;
	FRotator _rotation;
	FActorSpawnParameters _spawnInfo;
	OptionSections _buildingType;

	// Construction Timer
	AConstructionTimerActor* _constructionTimer;
	/**
	 * @brief Get the Construction Timer object
	 * 
	 */
	void GetConstructionTimer();

	// Current construction phase to control building functionality
	BuildingState *_bState;
protected:
	// Total time to construct the building
	float _timeInHours;

	int _buildingCost;
public:
	/**
	 * @brief Construct a new UBuilding object
	 * 
	 */
	UBuilding();
	/**
	 * @brief Destroy the UBuilding object
	 * 
	 */
	virtual ~UBuilding();

	int32* x;

	/**
	 * @brief Set the Building Cost object
	 * 
	 */
	virtual void SetBuildingCost();

	/**
	 * @brief Create a Building graphics object
	 * 
	 */
	void CreateBuilding();

	/**
	 * @brief Sets the location, rotation and spawnInfo for the building
	 * to be spawned.
	 * 
	 * @param location 
	 * @param rotation 
	 * @param spawnInfo 
	 */
	void BuildingConstruction(FVector location, FRotator rotation, FActorSpawnParameters spawnInfo);

	/**
	 * @brief Sets BuildingState to new ActiveState and adds + 1 to the buidlingType total amount
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
	 * @brief Set the State object
	 * 
	 * @param state 
	 */
	void SetState(BuildingState* state);

	/**
	 * @brief Set the Mesh object
	 * 
	 * @param option 
	 */
	void SetMesh(OptionSections option);

	/**
	 * @brief Get the State object
	 * 
	 * @return BuildingState* 
	 */
	BuildingState* GetState();

	/**
	 * @brief Get the Cost object
	 * 
	 * @return int 
	 */
	int GetCost() { return _buildingCost; }
};
//#endif