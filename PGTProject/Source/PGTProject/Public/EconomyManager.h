#pragma once

#include "CoreMinimal.h"
#include "Building.h"
#include "GameFramework/Actor.h"
#include "EconomyManager.generated.h"

UCLASS()
/**
 * @brief The Economy Manager actor to run in the scene
 * 
 * Stores a reference to the current resource amount as well as to what buildings are active in play.
 */
class PGTPROJECT_API AEconomyManager : public AActor
{
	GENERATED_BODY()

public:	
	Resources resources;
	
	UPROPERTY()
	/**
	 * @brief An array of (Active) Buildings
	 * 
	 * Holds all the buildings currently in the game.
	 */
	TArray<UBuilding*> ActiveBuildings;

	/* Editor-visible properties to have code-only starting buildings */
	UPROPERTY(EditAnywhere)		
	int32 MineralBuildings;
	UPROPERTY(EditAnywhere)
	int32 EnergyBuildings;
	UPROPERTY(EditAnywhere)
	int32 Houses;
	UPROPERTY(EditAnywhere)
	int32 FoodBuildings;

	/**
	 * @brief Initalizes the economy manager with base resources
	 * 
	 * And also creates code-only starting buildings if defined above.
	 */
	void InitResources();

protected:
	/**
	 * @brief Unreal Actor Implementation
	 * 
	 */
	virtual void BeginPlay() override;
};
