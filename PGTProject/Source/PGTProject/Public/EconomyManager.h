// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Building.h"
#include "GameFramework/Actor.h"
#include "EconomyManager.generated.h"

UCLASS()
class PGTPROJECT_API AEconomyManager : public AActor
{
	GENERATED_BODY()

public:	
	Resources resources;

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

	void InitResources();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
