// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Node.h"
#include "TestingTile.h"

class Pathfinding
{
private:
	vector<Node*> open;
	vector<Node*> closed;
	vector<TestingTile*> path;

	int HCost(Node* node, Node* targetNode);
	int FCost(Node* node);

	bool EqualNodes(Node* current, Node* targetNode);
	bool IsTransversable();
	bool IsInClosed(Node* node);
	pair<bool, Node*> IsInOpen(Node* node);
	bool IsShortestPath(Node* node);
	Node* GetNodeWithLowestCost();
	void buildPath(Node* startNode, Node* targetNode);
public:
	Pathfinding();
	vector<TestingTile*> AStarPathfinding(TestingTile* startNode, TestingTile* targetNode);
	~Pathfinding();
};
