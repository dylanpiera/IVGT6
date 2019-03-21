// Fill out your copyright notice in the Description page of Project Settings.

#include "HexGrid.h"
#include "HexActor.h"
#include <unordered_set>
//#include <minwindef.h>
//using namespace std;

//using namespace AHexActor;

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
	
}

// Called every frame
void AHexGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


/**
 * \brief Generates a Hexagonal grid of Hexes.
 * \param map_radius The radius from the center Hex.
 */
//void AHexGrid:: GenerateGrid(int map_radius)
//{
//	std::unordered_set<AHexActor::Hex> map;
//	for (int q = -map_radius; q <= map_radius; q++) {
//		int r1 = FGenericPlatformMath::Max(-map_radius, -q - map_radius);
//		int r2 = FGenericPlatformMath::Min(map_radius, -q + map_radius);
//		for (int r = r1; r <= r2; r++) {
//			map.insert(AHexActor::Hex(q, r, -q - r));
//		}
//	}
//}