
#include "TestPathfinding.h" // (UPDATE) Testing class

#include "Pathfinding.h"	// Pathfinding system
#include "TestingTile.h"	// (UPDATE) Testing class

ATestPathfinding::ATestPathfinding()
{
 	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATestPathfinding::BeginPlay()
{
	Super::BeginPlay();
	
	// Start Pathfinding Test
	UE_LOG(LogTemp, Warning, TEXT("---- Pathfinding Test"));

/*
	// Based on grid space create testing tiles
	vector<ITileObject> allTiles;
	for (int x = 0; x < 32; x++) {
		for (int y = 0; y < 32; y++) {
			allTiles.push_back(TestingTile(x, y));
		}
	}

	// Define start and end tiles
	TestingTile* startTile = &(allTiles[0]);
	TestingTile* endTile = &(allTiles[allTiles.size() - 1]);
	UE_LOG(LogTemp, Warning, TEXT("Start tile %d %d \n"), startTile->posX, startTile->posY);
	UE_LOG(LogTemp, Warning, TEXT("End tile %d %d \n"), endTile->posX, endTile->posY);

	// Test pathfinding system
	Pathfinding p;
	vector<TestingTile*> finalPath;
	finalPath = p.AStarPathfinding(startTile, endTile);
	UE_LOG(LogTemp, Warning, TEXT("Display Path"));
	for (auto element : finalPath) {
		UE_LOG(LogTemp, Warning, TEXT("Next tile %d %d\n"), element->posX, element->posY);
	}

	// End Pathfinding Test
	UE_LOG(LogTemp, Warning, TEXT("---- End of Pathfinding Test"));
*/
}

void ATestPathfinding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

