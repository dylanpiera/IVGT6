// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <iostream>
#include <vector>
#include "HexActor.h"
#include "Node.h"

using std::vector;
using std::pair;

class PGTPROJECT_API Graph
{
private:
	vector<Node> nodes;
public:
	Graph(vector<AHexActor*> hexTiles);
	~Graph();
};
