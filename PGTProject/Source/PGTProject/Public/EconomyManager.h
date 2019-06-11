#pragma once

#include "CoreMinimal.h"
#include "Building.h"
#include "GameFramework/Actor.h"
#include "EconomyManager.generated.h"

UCLASS()
/**
 * @brief 
 * 
 */
class PGTPROJECT_API AEconomyManager : public AActor
{
	GENERATED_BODY()

public:	
	Resources resources;
	
	UPROPERTY()
	/**
	 * @brief 
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
	 * @brief 
	 * 
	 */
	void InitResources();

protected:
	/**
	 * @brief 
	 * 
	 */
	virtual void BeginPlay() override;
};
