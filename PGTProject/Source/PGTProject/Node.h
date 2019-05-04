// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <iostream>
#include <vector>
#include "TestingTile.h"

using std::vector;

struct Node
{
public:
	// Reference for hextile
	TestingTile* HexTile;

	// Node costs
	int FCost;			// Total cost
	int HCost;			// Cost from the end node
	int GCost;			// Cost from the start node

	// Node parent (for backtracing path)
	Node* Parent;

	// Create a node 
	Node(TestingTile* hexTile);
	// Get node neighbors
	vector<TestingTile> GetNeighbors();
	// Get cost of visiting a node
	int GetCost();
	// Get distance from another node
	int GetDistanceFrom(Node* target);

	~Node();
};

