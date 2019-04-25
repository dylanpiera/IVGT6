// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EconomyManager.h"
#include "ToolbarActor.generated.h"


UCLASS()
class PGTPROJECT_API AToolbarActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AToolbarActor();
	int getEnergy();
	int getMinerals();
	int getMoney();
	int getPopulation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	int currentTool;
	int currentMode;

private:
	AEconomyManager* _econ_manager;

public:	
	void testFunc();

	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
