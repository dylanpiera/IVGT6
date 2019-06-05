// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Building.h"
#include "GameFramework/Actor.h"
#include "ConstructionTimerActor.generated.h"

UCLASS()
class PGTPROJECT_API AConstructionTimerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConstructionTimerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Start construction timer for building
	void StartConstruction(UBuilding* building, float TimeInHours);
	// Warn building time is over
	void FinishConstruction(UBuilding* building);
};
