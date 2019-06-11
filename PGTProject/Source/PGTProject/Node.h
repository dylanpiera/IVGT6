#pragma once

#include "CoreMinimal.h"
#include <iostream>
#include <vector>
#include "TestingTile.h"

using std::vector;
/**
 * @struct Node
 * @brief Auxiliar struct for pathfinding. 
 * 
 */
struct Node
{
public:
	/**
	 * @var HexTile
	 * @brief Reference to an existing tile in the game.
	*/
	TestingTile* HexTile;

	/**
	 * @var FCost
	 * @brief Total cost of node: HCost + GCost
	 *
	 * @var HCost
	 * @brief Cost from the "end" node in path.
	 *
	 * @var GCost
	 * @brief Cost from the "start" node in path.
	*/
	int FCost;
	int HCost;
	int GCost;

	/**
	 * @var Parent
	 * @brief Parent of this node (used for backtracing path)
	*/
	Node* Parent;

	/**
	 * @brief Create a new Node with a reference for a hextile and initilizing the node costs
	 * 
	 * @param hexTile 
	 */
	Node(TestingTile* hexTile);
	/**
	 * @brief Get all neighbors from current hextile
	 * 
	 * @return vector<TestingTile> 
	 */
	vector<TestingTile> GetNeighbors();
	/**
	 * @brief Get cost of visiting the node
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
	 * @brief Default destructor
	 * 
	 */
	~Node();
};

