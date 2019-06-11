#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Building.h"
#include "GameFramework/Actor.h"
#include "ConstructionTimerActor.generated.h"

UCLASS()
/**
 * @brief 
 * 
 */
class PGTPROJECT_API AConstructionTimerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	/**
	 * @brief Construct a new AConstructionTimerActor object
	 * 
	 */
	AConstructionTimerActor();

protected:
	/**
	 * @brief 
	 * 
	 */
	virtual void BeginPlay() override;

public:	
	/**
	 * @brief 
	 * 
	 * @param DeltaTime 
	 */
	virtual void Tick(float DeltaTime) override;

	/**
	 * @brief 
	 * 
	 * @param building 
	 * @param TimeInHours 
	 */
	void StartConstruction(UBuilding* building, float TimeInHours);

	/**
	 * @brief 
	 * 
	 * @param building 
	 */
	void FinishConstruction(UBuilding* building);
};
