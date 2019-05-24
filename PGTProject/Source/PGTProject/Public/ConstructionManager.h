// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ConstructionTimerActor.h"
#include "GameFramework/Actor.h"
#include "ConstructionManager.generated.h"


UCLASS()
class PGTPROJECT_API AConstructionManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConstructionManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	AConstructionTimerActor* _mainConstructionTimer;
};
