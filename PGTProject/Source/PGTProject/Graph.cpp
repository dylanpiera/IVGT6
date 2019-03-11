// Fill out your copyright notice in the Description page of Project Settings.

#include "Graph.h"

Graph::Graph(vector<AHexActor*> hexTiles)
{
	for (auto hexTile : hexTiles) {
		Node newNode = Node(hexTile);
		// Add newNodeNeighbours
		nodes.push_back(newNode);
	}
}

Graph::~Graph()
{
}
