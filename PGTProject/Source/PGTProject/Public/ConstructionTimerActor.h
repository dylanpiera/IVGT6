#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Building.h"
#include "GameFramework/Actor.h"
#include "ConstructionTimerActor.generated.h"

UCLASS()
/**
 * @class Construction Timer
 * @brief Class used to set a timer to simulate a construction for a building.
 * The timer is triggered by a building and when the timer is finished the building is notified. 
 */
class PGTPROJECT_API AConstructionTimerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	/**
	 * @brief Default constructor for Unreal Actor
	 * 
	 */
	AConstructionTimerActor();

protected:
	/**
	 * @brief Default function for Unreal Actor called when Actor starts/spawned
	 * 
	 */
	virtual void BeginPlay() override;

public:	
	/**
	 * @brief Default function for Unreal Actor called every frame
	 * 
	 * @param DeltaTime 
	 */
	virtual void Tick(float DeltaTime) override;

	/**
	 * @brief Start Unreal timer to simulate construction.
	 * The timer will end after the amount of time specified, and trigger a notification to the building who called it.
	 * 
	 * @param building 
	 * @param TimeInHours 
	 */
	void StartConstruction(UBuilding* building, float TimeInHours);

	/**
	 * @brief Notify building that the timer is done.
	 * 
	 * @param building 
	 */
	void FinishConstruction(UBuilding* building);
};
