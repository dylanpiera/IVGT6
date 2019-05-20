// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingTile.h"

// (UPDATE) Test class

// Create tile based on position
TestingTile::TestingTile(int x, int y)
{
	posX = x;
	posY = y;
}

// Get tile neighbors
vector<TestingTile> TestingTile::GetNeighbours()
{
	vector<TestingTile> neighbors;

	if (posX + 1 < 32)
	{
		TestingTile n = TestingTile(posX + 1, posY);
		neighbors.push_back(n);
	}
	if (posY + 1 < 32)
	{
		TestingTile n = TestingTile(posX, posY + 1);
		neighbors.push_back(n);
	}
	if (posX + 1 < 32 && posY + 1 < 32)
	{
		TestingTile n = TestingTile(posX + 1, posY + 1);
		neighbors.push_back(n);
	}
	if (posX - 1 >= 0)
	{
		TestingTile n = TestingTile(posX - 1, posY);
		neighbors.push_back(n);
	}
	if (posY - 1 >= 0)
	{
		TestingTile n = TestingTile(posX, posY - 1);
		neighbors.push_back(n);
	}
	if (posX - 1 >= 0 && posY - 1 >= 0)
	{
		TestingTile n = TestingTile(posX - 1, posY - 1);
		neighbors.push_back(n);
	}
	return neighbors;
}

int TestingTile::GetCost()
{
	return 10;
}

int TestingTile::GetDistanceFrom(TestingTile* other)
{
	return sqrt(pow(other->posX - posX, 2) + pow(other->posY - posY, 2));
}

TestingTile::~TestingTile()
{
}
