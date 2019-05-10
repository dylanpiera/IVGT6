// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MineralBuilding.h"
#include "Components/BoxComponent.h"
#include "ConstructorHelpers.h"
#include "EconomyManager.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "BuildingGraphics.generated.h"

UCLASS()
class PGTPROJECT_API ABuildingGraphics : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuildingGraphics();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UStaticMesh* BuildingMesh;
	UMaterial* BuildingMaterial;

	MineralBuilding* Building;
	AEconomyManager* EcoMan;

};
