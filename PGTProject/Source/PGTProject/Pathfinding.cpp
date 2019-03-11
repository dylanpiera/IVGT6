// Fill out your copyright notice in the Description page of Project Settings.

#include "Pathfinding.h"
#include <GraphAStar.h>
#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::pair;

// Constructor
Pathfinding::Pathfinding() { }

void Pathfinding::AStarPathfinding(Node startNode, Node targetNode) {
	vector<Node> open;
	vector<Node> closed;

	open.push_back(startNode);

	while (open.size() > 0) {
		// Get node in open with the lowest FCost
		Node* current = GetNodeWithLowestCost(open);
		closed.push_back(*current);

		if (EqualNodes(*current, targetNode)) {
			return;
		}

		for (auto neighbor : (*current).neighbors) {
			if (!IsTransversable() || IsInClosed(neighbor, closed)) {
				continue;
			}
			bool neighborIsInOpen = IsInOpen(neighbor, open);
			if ((neighborIsInOpen && IsShortestPath(neighbor, open)) || !neighborIsInOpen) {
				neighbor.fcost = FCost(neighbor, targetNode);
				neighbor.parent = current;
				if (!neighborIsInOpen) {
					open.push_back(neighbor);
				}
			}
		}
	}
}

bool Pathfinding::IsShortestPath(Node node, vector<Node> open) {
	Node* nodeWithShortestPath;
	int bestFCost;
	bool firstTime = true;

	for (auto openedNode : open) {
		if (firstTime || openedNode.fcost < bestFCost) {
			nodeWithShortestPath = &openedNode;
			bestFCost = openedNode.fcost;
			firstTime = false;
		}
	}
	if (EqualNodes(*nodeWithShortestPath, node)) {
		return true;
	}
	return false;
}

bool Pathfinding::IsInOpen(Node node, vector<Node> open) {
	for (auto openedNode : open) {
		if (EqualNodes(node, openedNode)) {
			return true;
		}
	}
	return false;
}

bool Pathfinding::IsInClosed(Node node, vector<Node> closed) {
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

bool Pathfinding::EqualNodes(Node current, Node targetNode) {
	
}

Node* Pathfinding::GetNodeWithLowestCost(vector<Node> open) {
	Node* nodeWithLowestCost;
	int bestFCost;
	bool firstTime = true;

	vector<Node>::iterator it = open.begin();
	vector<Node>::iterator index;

	for (auto openedNode : open) {
		if (firstTime || openedNode.fcost < bestFCost) {
			nodeWithLowestCost = &openedNode;
			bestFCost = openedNode.fcost;
			index = it;
			firstTime = false;
		}
		it++;
	}

	open.erase(index);
	return nodeWithLowestCost;
}

int Pathfinding::GCost(Node node) { // Cost of visiting the node

}

int Pathfinding::HCost(Node node, Node targetNode) { // Cost from the end node (distance)
	
}

int Pathfinding::FCost(Node node, Node targetNode) { // Total cost
	return GCost(node) + HCost(node, targetNode);

}

Pathfinding::~Pathfinding()
{
}
