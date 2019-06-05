// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <iostream>
#include <vector>
#include "TestingTile.h"

class AHexGridManager;
class AHexActor;
using std::vector;

struct Node
{
public:
	// HexGrid Manager reference
	AHexGridManager* _hexGridManager;

	// Reference for hextile
	AHexActor* HexTile;

	// Node costs
	int FCost;			// Total cost
	int HCost;			// Cost from the end node
	int GCost;			// Cost from the start node

	// Node parent (for backtracing path)
	Node* Parent;

	// Create a node 
	Node(AHexActor* hexTile);
	// Get node neighbors
	vector<AHexActor*> GetNeighbors();
	// Get cost of visiting a node
	int GetCost();
	// Get distance from another node
	int GetDistanceFrom(Node* target);
	// Get reference to HexGridManager
	void FindHexGridManager();
	// Check if two nodes reference the same HexActor
	bool EqualNodes(Node* other);

	~Node();
};

