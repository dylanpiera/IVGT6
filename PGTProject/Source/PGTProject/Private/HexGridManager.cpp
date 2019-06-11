

#include "HexGridManager.h"
#include "HexActor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>

// Sets default values
AHexGridManager::AHexGridManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHexGridManager::BeginPlay()
{
	Super::BeginPlay();

	//Testing
	GenerateGrid();
	LogGrid();

	//TestPathfind();
}

// Called every frame
void AHexGridManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHexGridManager::GenerateGrid()
{
	for (int column = 0; column < mapsize; column++)
	{
		for(int row = 0; row < mapsize; row++)
		{
			auto* hex = new AHexActor::Hex(column, row);
			hexes[column][row] = hex;
			
			FRotator Rotation(0.0f, 0.0f, 0.0f);
			FActorSpawnParameters SpawnInfo;
			AHexActor* a = GetWorld()->SpawnActor<AHexActor>(AHexActor::GetScreenSpaceLocation(hex), Rotation, SpawnInfo);
			a->hex = hex; // this is for getting grid position

			_tiles.push_back(a);
		}
	}
}

void AHexGridManager::LogGrid() const
{
	for (int column = 0; column < mapsize; column++)
	{
		for (int row = 0; row < mapsize; row++)
		{
			UE_LOG(LogTemp, Warning, TEXT("q: %d - r: %d - s: %d"), hexes[column][row]->q, hexes[column][row]->r, hexes[column][row]->s);
		}
	}
}

// Find HexActor reference by hex 
AHexActor* AHexGridManager::GetHexActorFromHex(AHexActor::Hex myHex)
{
	for (auto iter = _tiles.begin(); iter != _tiles.end(); iter++) {
		AHexActor* hex_actor = *iter;
		if (hex_actor->hex_equal(*(hex_actor->hex), myHex))
		{
			return hex_actor;
			break;
		}
	}
	return NULL;
}

/*
void AHexGridManager::TestPathfind()
{
	// Define start and end tiles
	AHexActor* startTile = _tiles.at(5);
	AHexActor* endTile = _tiles.at(50);
	
	// Test pathfinding system
	Pathfinding p;
	list<AHexActor*> finalPath;
	finalPath = p.AStarPathfinding(startTile, endTile);
	for (auto element : finalPath) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Next tile column: %d row: %d"), element->hex->q, element->hex->r));
	}
}
*/