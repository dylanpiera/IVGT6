#pragma once

#include "CoreMinimal.h"
#include "Node.h"
#include "TestingTile.h" // (UPDATE) Test class

using namespace std;
/**
 * @brief 
 * 
 */
class Pathfinding
{
private:
	vector<Node*> Open;										// Open nodes list
	vector<Node*> Closed;									// Closed nodes list
	vector<TestingTile*> Path;								// Nodes path list

	/**
	 * @brief Cost from the end node
	 * 
	 * @param node 
	 * @param targetNode 
	 * @return int 
	 */
	int HCost(Node* node, Node* targetNode);
	/**
	 * @brief Total cost for a node
	 * 
	 * @param node 
	 * @return int 
	 */
	int FCost(Node* node);

	/**
	 * @brief Check if nodeA is equal to nodeB
	 * 
	 * @param nodeA 
	 * @param nodeB 
	 * @return true 
	 * @return false 
	 */
	bool EqualNodes(Node* nodeA, Node* nodeB);
	/**
	 * @brief Check if node is transversable (if node can be visited)
	 * 
	 * @return true 
	 * @return false 
	 */
	bool IsTransversable();
	/**
	 * @brief Check if a node is in the closed list
	 * 
	 * @param node 
	 * @return true 
	 * @return false 
	 */
	bool IsInClosed(Node* node);
	/**
	 * @brief Check if a node is the open list
	 * 
	 * @param node 
	 * @return pair<bool, Node*> 
	 */
	pair<bool, Node*> IsInOpen(Node* node);
	/**
	 * @brief Search for node with the lowest cost in open list
	 * 
	 * @return Node* 
	 */
	Node* GetNodeWithLowestCost();
	/**
	 * @brief Build path from start node to target node
	 * 
	 * @param startNode 
	 * @param targetNode 
	 */
	void BuildPath(Node* startNode, Node* targetNode);

public:
	
	/**
	 * @brief A* Pathfinding: receives a start tile and an end tile and returns the path
	 * 
	 * @param startNode 
	 * @param targetNode 
	 * @return vector<TestingTile*> 
	 */
	vector<TestingTile*> AStarPathfinding(TestingTile* startNode, TestingTile* targetNode);
	/**
	 * @brief Construct a new Pathfinding object
	 * 
	 */
	Pathfinding();
	/**
	 * @brief Destroy the Pathfinding object
	 * 
	 */
	~Pathfinding();
};
