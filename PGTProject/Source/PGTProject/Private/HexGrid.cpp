// Fill out your copyright notice in the Description page of Project Settings.

#include "HexGrid.h"
#include "HexActor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>


// Sets default values
AHexGrid::AHexGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHexGrid::BeginPlay()
{
	Super::BeginPlay();
	GenerateGrid();
	LogGrid();
}

// Called every frame
void AHexGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHexGrid::GenerateGrid()
{
	for (int column = 0; column < mapsize; column++)
	{
		for(int row = 0; row < mapsize; row++)
		{
			auto* hex = new AHexActor::Hex(column, row);
			hexes[column][row] = hex;

			//TODO: Spawn AHexObject in World Space
			
			FRotator Rotation(0.0f, 0.0f, 0.0f);
			FActorSpawnParameters SpawnInfo;
			AHexActor* a = GetWorld()->SpawnActor<AHexActor>(AHexActor::GetScreenSpaceLocation(hex), Rotation, SpawnInfo);

		}
	}
}

void AHexGrid::LogGrid() const
{
	for (int column = 0; column < mapsize; column++)
	{
		for (int row = 0; row < mapsize; row++)
		{
			UE_LOG(LogTemp, Warning, TEXT("q: %d - r: %d - s: %d"), hexes[column][row]->q, hexes[column][row]->r, hexes[column][row]->s);
		}
	}
}
