// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <iostream>
#include <vector>
#include "ITileObject.h"

using std::vector;
using std::pair;

class PGTPROJECT_API Node
{
public:
	ITileObject* node;
	vector<Node> neighbors;
	int fcost;
	Node* parent;

	Node(ITileObject* hexTile);
	void AddNeighbour(Node next);
	~Node();
};
