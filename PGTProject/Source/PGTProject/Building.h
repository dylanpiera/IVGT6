//#ifndef BuildingObject_Header
//#define BuildingObject_Header
#pragma once
#include "Resources.h"
#include "Constants.h"
#include "Runtime/Core/Public/Math/Vector.h"
#include "Engine/World.h"
#include "UObject/NoExportTypes.h"
#include "Building.generated.h"

/**
 * @brief 
 * 
 */
class AConstructionTimerActor;
/**
 * @brief 
 * 
 */
class ABuildingGraphics;
/**
 * @brief 
 * 
 */
class BuildingState;

UCLASS()
/**
 * @brief 
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
	 * @brief 
	 * 
	 * @param location 
	 * @param rotation 
	 * @param spawnInfo 
	 */
	void BuildingConstruction(FVector location, FRotator rotation, FActorSpawnParameters spawnInfo);

	/**
	 * @brief Function called when time is over
	 * 
	 */
	void WhenConstructionFinishes();

	/*
	 * override this and implement what the building needs to update
	*/
	virtual void BuildingActive(Resources &resource, Resources &maintenance);

	/**
	 * @brief 
	 * 
	 * @param resource 
	 */
	virtual void BuildingFunction(Resources &resource);

	/**
	 * @brief 
	 * 
	 * @param resource 
	 */
	virtual void BuildingUpkeep(Resources &resource);

	/**
	 * @brief 
	 * 
	 */
	virtual void BuildingInactive();

	/**
	 * @brief 
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