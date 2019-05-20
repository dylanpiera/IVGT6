// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Testing_ToolbarGraphics.generated.h"

UCLASS()
class PGTPROJECT_API ATesting_ToolbarGraphics : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATesting_ToolbarGraphics();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
