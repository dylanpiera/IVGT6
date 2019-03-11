// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Graph.h"
#include "Node.h"

class PGTPROJECT_API Pathfinding
{
private:
	int GCost(Node node);
	int HCost(Node node, Node targetNode);
	int FCost(Node node, Node targetNode);

	bool EqualNodes(Node current, Node targetNode);
	bool IsTransversable();
	bool IsInClosed(Node node, vector<Node> closed);
	bool IsInOpen(Node node, vector<Node> open);
	bool IsShortestPath(Node node, vector<Node> open);
public:
	Pathfinding();
	void AStarPathfinding(Node startNode, Node targetNode);
	Node* GetNodeWithLowestCost(vector<Node> open);

	~Pathfinding();
};
