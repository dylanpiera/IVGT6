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
	TestingTile* node;

	// Node costs
	int fcost;			// Total cost
	int hcost;			// Cost from the end node
	int gcost;			// Cost from the start node

	// Node parent (for backtracing path)
	Node* parent;

	// Creating a node 
	Node(TestingTile* hexTile);

	vector<TestingTile> GetNeighbors();
	int GetCost();
	int GetDistanceFrom(Node* target);

	~Node();
};

