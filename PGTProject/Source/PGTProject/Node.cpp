// Fill out your copyright notice in the Description page of Project Settings.

#include "Node.h"

Node::Node(ITileObject* hexTile) {
	node = hexTile;
}

void Node::AddNeighbour(Node next) {
	neighbors.push_back(Node(next));
}

Node::~Node()
{
}
