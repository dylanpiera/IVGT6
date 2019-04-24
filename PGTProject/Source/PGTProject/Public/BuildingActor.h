// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Constants.h"
#include "BuildingActorGraphics.h"
#include "GameFramework/Actor.h"
#include "BuildingActor.generated.h"

UCLASS()
class PGTPROJECT_API ABuildingActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABuildingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	struct _Building
	{
		// building type
		EBuildingType BuildingType;

		// building texture
		BuildingActorGraphics Graphics;
	};

	// virtual building function
	virtual void BuildingFunction();
		// function for adding to building type list (for economy manager)

};
