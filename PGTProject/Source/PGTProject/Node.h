#pragma once

#include "CoreMinimal.h"
#include <iostream>
#include <vector>
#include "TestingTile.h"

using std::vector;
/**
 * @brief 
 * 
 */
struct Node
{
public:
	// Reference for hextile
	TestingTile* HexTile;

	// Node costs
	int FCost;			// Total cost
	int HCost;			// Cost from the end node
	int GCost;			// Cost from the start node

	// Node parent (for backtracing path)
	Node* Parent;

	/**
	 * @brief Construct a new Node object
	 * 
	 * @param hexTile 
	 */
	Node(TestingTile* hexTile);
	/**
	 * @brief Get the Neighbors object
	 * 
	 * @return vector<TestingTile> 
	 */
	vector<TestingTile> GetNeighbors();
	/**
	 * @brief Get cost of visiting a node
	 * 
	 * @return int 
	 */
	int GetCost();
	/**
	 * @brief Get distance from another node
	 * 
	 * @param target 
	 * @return int 
	 */
	int GetDistanceFrom(Node* target);

	/**
	 * @brief Destroy the Node object
	 * 
	 */
	~Node();
};

