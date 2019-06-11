#pragma once

#include "CoreMinimal.h"
#include "Building.h"
#include "GameFramework/Actor.h"
#include "EconomyManager.generated.h"

UCLASS()
/**
 * @brief Sets up buildings and starting values for resources
 * 
 */
class PGTPROJECT_API AEconomyManager : public AActor
{
	GENERATED_BODY()

public:	
	Resources resources;
	
	UPROPERTY()
	/**
	 * @brief Makes a list to put active buildings in
	 * 
	 */
	TArray<UBuilding*> ActiveBuildings;

	/* for testing purposes: */
	UPROPERTY(EditAnywhere)		
	int32 MineralBuildings;
	UPROPERTY(EditAnywhere)
	int32 EnergyBuildings;
	UPROPERTY(EditAnywhere)
	int32 Houses;
	UPROPERTY(EditAnywhere)
	int32 FoodBuildings;

	/**
	 * @brief Set starting values of resources
	 * 
	 */
	void InitResources();

protected:
	/**
	 * @brief Sets buildings at the start of the game
	 * 
	 */
	virtual void BeginPlay() override;
};
