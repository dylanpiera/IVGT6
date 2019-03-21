// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <vector>

using std::vector;

class TestingTile
{
public:
	int posX;
	int posY;
	int GetCost();
	vector<TestingTile> GetNeighbours();
	int GetDistanceFrom(TestingTile* other);

	TestingTile(int x, int y);
	~TestingTile();
};

