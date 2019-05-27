// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BuildingObject.h"
#include "GameFramework/Actor.h"
#include "EconomyManager.generated.h"

UCLASS()
class PGTPROJECT_API AEconomyManager : public AActor
{
	GENERATED_BODY()

public:	
	Resources resources;

	TArray<BuildingObject*> ActiveBuildings;

	/* for testing purposes: */
	UPROPERTY(EditAnywhere)		
	int32 MineralBuildings;
	UPROPERTY(EditAnywhere)
	int32 EnergyBuildings;
	UPROPERTY(EditAnywhere)
	int32 Houses;

	void InitResources();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
