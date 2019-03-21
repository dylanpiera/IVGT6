// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <iostream>
#include <vector>
//#include "ITileObject.h"
#include "TestingTile.h"

using std::vector;
using std::pair;

struct Node
{
public:
	//ITileObject* node;
	TestingTile* node;
	int fcost;
	int hcost;
	int gcost;
	Node* parent;

	//Node(ITileObject* hexTile);
	Node(TestingTile* hexTile);

	vector<TestingTile> GetNeighbors();
	int GetCost();
	int GetDistanceFrom(Node* target);

	~Node();
};

