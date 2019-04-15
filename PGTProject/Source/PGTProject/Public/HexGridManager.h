// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HexActor.h"
#include "GameFramework/Actor.h"
#include "HexGridManager.generated.h"

UCLASS()
class PGTPROJECT_API AHexGridManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHexGridManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void GenerateGrid();
	void LogGrid() const;

	const int mapsize = 32;

	AHexActor::Hex *hexes[32][32];
};
