#pragma once

#include "CoreMinimal.h"
#include <iostream>
#include <vector>

class AHexGridManager;
class AHexActor;
using std::vector;
/**
 * @brief 
 * 
 */
struct Node
{
public:
	// HexGrid Manager reference
	AHexGridManager* _hexGridManager;

	// Reference for hextile
	AHexActor* HexTile;

	// Node costs
	int FCost;			// Total cost
	int HCost;			// Cost from the end node
	int GCost;			// Cost from the start node

	// Node parent (for backtracing path)
	Node* Parent;

	// Create a node 
	Node(AHexActor* hexTile);
	// Get node neighbors
	vector<AHexActor*> GetNeighbors();
	// Get cost of visiting a node
	int GetCost();
	/**
	 * @brief Get distance from another node
	 * 
	 * @param target 
	 * @return int 
	 */
	int GetDistanceFrom(Node* target);
	// Get reference to HexGridManager
	void FindHexGridManager();
	// Check if two nodes reference the same HexActor
	bool EqualNodes(Node* other);

	/**
	 * @brief Destroy the Node object
	 * 
	 */
	~Node();
};

