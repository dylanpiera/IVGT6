// Fill out your copyright notice in the Description page of Project Settings.

#include "Pathfinding.h"
#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::pair;

// Constructor
Pathfinding::Pathfinding() {
}

vector<TestingTile*> Pathfinding::AStarPathfinding(TestingTile* startTile, TestingTile* targetTile) {
	Node startNode = Node(startTile);
	Node targetNode = Node(targetTile);
	startNode.hcost = HCost(&startNode, &targetNode);
	startNode.fcost = FCost(&startNode);
	targetNode.hcost = HCost(&targetNode, &targetNode);
	targetNode.fcost = FCost(&targetNode);

	bool reachedTargetNode = false;
	open.push_back(&startNode);

	while (open.size() > 0 && !reachedTargetNode) {
		// Get node in open with the lowest FCost
		Node* current = GetNodeWithLowestCost();
		closed.push_back(current);

		if (EqualNodes(current, &targetNode)) {
			targetNode.parent = current->parent;
			reachedTargetNode = true;
			continue;
		}

		for (auto neighbor : current->GetNeighbors()) {
			TestingTile* t = new TestingTile(neighbor);
			Node* newNeighbor = new Node(t);

			if (!IsTransversable() || IsInClosed(newNeighbor)) {
				continue;
			}

			pair<bool, Node*> result = IsInOpen(newNeighbor);
			bool neighborIsInOpen = result.first;
			Node* realNeighbor = result.second;

			int movementCost = current->gcost + realNeighbor->GetCost(); // Cost so far from the starting node + cost of visiting the neighbor
			if (!neighborIsInOpen || movementCost < realNeighbor->gcost) {
				realNeighbor->gcost = movementCost;
				realNeighbor->hcost = HCost(realNeighbor, &targetNode);
				realNeighbor->fcost = FCost(realNeighbor);

				realNeighbor->parent = current;
				if (!neighborIsInOpen) {
					open.push_back(realNeighbor);
				}
			}
		}
	}

	buildPath(&startNode, &targetNode);
	return path;
}

void Pathfinding::buildPath(Node* startNode, Node* targetNode) {
	bool reachedStartNode = false;
	Node* current = targetNode;
	while (!reachedStartNode) {
		TestingTile* tile = current->node;
		path.push_back(tile);

		if (EqualNodes(current, startNode)) {
			reachedStartNode = true;
		}
		else {
			current = current->parent;
		}
	}

	std::reverse(path.begin(), path.end());
}

bool Pathfinding::IsShortestPath(Node* node) {
	Node* nodeWithShortestPath = NULL;
	int bestFCost;
	bool firstTime = true;

	for (auto openedNode : open) {
		if (firstTime || openedNode->fcost < bestFCost) {
			nodeWithShortestPath = openedNode;
			bestFCost = openedNode->fcost;
			firstTime = false;
		}
	}
	if (!firstTime) {
		if (EqualNodes(nodeWithShortestPath, node)) {
			return true;
		}
	}
	return false;
}

pair<bool, Node*> Pathfinding::IsInOpen(Node* node) {
	Node* realNeighbor = NULL;
	for (auto openedNode : open) {
		if (EqualNodes(node, openedNode)) {
			realNeighbor = openedNode;
			return pair<bool, Node*>(true, realNeighbor);
		}
	}
	realNeighbor = node;
	return pair<bool, Node*>(false, realNeighbor);
}

bool Pathfinding::IsInClosed(Node* node) {
	for (auto closedNode : closed) {
		if (EqualNodes(node, closedNode)) {
			return true;
		}
	}
	return false;
}

bool Pathfinding::IsTransversable() {
	return true;
}

bool Pathfinding::EqualNodes(Node* current, Node* targetNode) {
	if (current->node->posX == targetNode->node->posX
		&& current->node->posY == targetNode->node->posY) {
		return true;
	}
	return false;
}

Node* Pathfinding::GetNodeWithLowestCost() {
	Node* nodeWithLowestCost = NULL;
	bool firstTime = true;
	int i = 0, index = 0;

	for (auto openedNode : open) {
		if (firstTime || openedNode->fcost < nodeWithLowestCost->fcost || (openedNode->fcost == nodeWithLowestCost->fcost && openedNode->hcost < nodeWithLowestCost->hcost)) {
			nodeWithLowestCost = openedNode;
			index = i;
			firstTime = false;
		}
		i++;
	}

	open.erase(open.begin() + index);
	return nodeWithLowestCost;
}

int Pathfinding::HCost(Node* node, Node* targetNode) { // Cost from the end node (distance)
	return node->GetDistanceFrom(targetNode);
}

int Pathfinding::FCost(Node* node) { // Total cost
	return node->gcost + node->hcost;
}

Pathfinding::~Pathfinding()
{
}
