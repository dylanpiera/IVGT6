// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <iostream>
#include <vector>
#include "Node.h"
//#include "ITileObject.h"
#include <TestingTile.h>

using std::vector;
using std::pair;

class PGTPROJECT_API Graph
{
private:
	vector<Node> nodes;
public:
//	Graph(vector<ITileObject*> hexTiles);
	Graph(vector<TestingTile*> hexTiles);

	~Graph();
};
