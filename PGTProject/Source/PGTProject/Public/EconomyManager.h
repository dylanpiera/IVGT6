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
};
