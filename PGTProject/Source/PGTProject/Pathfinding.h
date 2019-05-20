// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Node.h"
#include "TestingTile.h" // (UPDATE) Test class

using namespace std;

class Pathfinding
{
private:
	vector<Node*> Open;										// Open nodes list
	vector<Node*> Closed;									// Closed nodes list
	vector<TestingTile*> Path;								// Nodes path list

	int HCost(Node* node, Node* targetNode);				// Cost from the end node
	int FCost(Node* node);									// Total cost for a node

	bool EqualNodes(Node* nodeA, Node* nodeB);				// Check if nodeA is equal to nodeB
	bool IsTransversable();									// Check if node is transversable (if node can be visited)
	bool IsInClosed(Node* node);							// Check if a node is in the closed list
	pair<bool, Node*> IsInOpen(Node* node);					// Check if a node is the open list
	Node* GetNodeWithLowestCost();							// Search for node with the lowest cost in open list
	void BuildPath(Node* startNode, Node* targetNode);		// Build path from start node to target node

public:
	
	// A* Pathfinding: receives a start tile and an end tile and returns the path
	vector<TestingTile*> AStarPathfinding(TestingTile* startNode, TestingTile* targetNode);
	
	Pathfinding();		// Constructor
	~Pathfinding();		// Destructor
};
