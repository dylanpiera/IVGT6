#pragma once

#include "CoreMinimal.h"
#include "Node.h"
#include "HexActor.h"
#include <list>

using namespace std;
/**
 * @class Pathfinding
 * @brief Find a path between two hextiles, with A* algorithm.
 * The path is a collection of hextiles that leads from the start tile to the end tile.
 * 
 */
class Pathfinding
{
private:
	/**
	 * @var Open
	 * @brief Collection of open nodes (available nodes to evaluate if should be on path)
	 * 
	 * @var Closed
	 * @brief Collection of closed nodes (already evaluated nodes to be on path)
	 * 
	 * @var Path
	 * @brief Collection of hextiles that leads from the start tile to the end tile.
	 */

	vector<Node*> Open;	
	vector<Node*> Closed;
	list<AHexActor*> Path;

	/**
	 * @brief Calculate cost to go from the current node to the "end" node 
	 * 
	 * @param node 
	 * @param targetNode 
	 * @return int 
	 */
	int HCost(Node* node, Node* targetNode);
	/**
	 * @brief Calculate total cost of a node
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
	 * @brief A* Pathfinding: Calculates a path of tiles that leads from a start tile to a target tile.
	 * 
	 * @param startNode 
	 * @param targetNode 
	 * @return vector<TestingTile*> 
	 */
	list<AHexActor*> AStarPathfinding(AHexActor* startNode, AHexActor* targetNode);
	/**
	 * @brief Default constructor
	 * 
	 */
	Pathfinding();
	/**
	 * @brief Default destructor
	 * 
	 */
	~Pathfinding();
};
