// Fill out your copyright notice in the Description page of Project Settings.

#include "Lucia.h"
#include "TestingTile.h"
#include "Pathfinding.h"
#include "definitions.h"

// Sets default values
ALucia::ALucia()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALucia::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("LUCIA BEGINS"));
	
	vector<TestingTile> allTiles;
	for (int x = 0; x < gridX; x++) {
		for (int y = 0; y < gridY; y++) {
			allTiles.push_back(TestingTile(x, y));
		}
	}

	TestingTile* startTile = &(allTiles[0]);
	TestingTile* endTile = &(allTiles[allTiles.size() - 1]);
	Pathfinding p;
	vector<TestingTile*> finalPath;

	UE_LOG(LogTemp, Warning, TEXT("START TILE %d %d \n"), startTile->posX, startTile->posY);
	UE_LOG(LogTemp, Warning, TEXT("END TILE %d %d \n"), endTile->posX, endTile->posY);

	finalPath = p.AStarPathfinding(startTile, endTile);

	for (auto element : finalPath) {
		UE_LOG(LogTemp, Warning, TEXT("PATH ELEMENT %d %d\n"), element->posX, element->posY);
	}

	UE_LOG(LogTemp, Warning, TEXT("LUCIA BEGINS ---"));

}

// Called every frame
void ALucia::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
