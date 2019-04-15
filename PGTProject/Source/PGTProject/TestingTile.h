// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <vector>

using std::vector;

// (UPDATE) Test class

class TestingTile
{
public:
	int posX;									// Tile position
	int posY;
	
	int GetCost();								// Get cost of visiting this tile
	vector<TestingTile> GetNeighbours();		// Get tile neighbors
	int GetDistanceFrom(TestingTile* other);	// Get distance between this tile and a received tile (other)

	TestingTile(int x, int y);					// Constructor
	~TestingTile();								// Destructor
};

