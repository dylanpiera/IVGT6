#pragma once

#include "CoreMinimal.h"
#include "Node.h"
#include "HexActor.h"
#include <list>

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
	list<AHexActor*> Path;								// Nodes path list
	
	int HCost(Node* node, Node* targetNode);				// Cost from the end node
	int FCost(Node* node);									// Total cost for a node

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
	
	// A* Pathfinding: receives a start tile and an end tile and returns the path
	list<AHexActor*> AStarPathfinding(AHexActor* startNode, AHexActor* targetNode);

	Pathfinding();		// Constructor
	~Pathfinding();		// Destructor
};
