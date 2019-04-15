#include "Pathfinding.h"
#include <vector>

using std::vector;
using std::pair;

// Constructor
Pathfinding::Pathfinding() {
}

// A* Pathfinding: receives a start tile and an end tile and returns the path
vector<TestingTile*> Pathfinding::AStarPathfinding(TestingTile* startTile, TestingTile* targetTile) {
	// Reset pathfinding elements
	open.clear();
	closed.clear();
	path.clear();

	// Initialize start and end nodes
	Node startNode = Node(startTile);
	Node targetNode = Node(targetTile);
	startNode.hcost = HCost(&startNode, &targetNode);
	startNode.fcost = FCost(&startNode);
	targetNode.hcost = HCost(&targetNode, &targetNode);
	targetNode.fcost = FCost(&targetNode);

	// Add start node to open nodes
	open.push_back(&startNode);

	// Define end path control
	bool reachedTargetNode = false;

	// While there are still nodes to be opened or haven't reached the end of the path
	while (open.size() > 0 && !reachedTargetNode) {
		// Get node in open list with the lowest FCost and remove it from open list
		Node* current = GetNodeWithLowestCost();
		// Add it to closed list
		closed.push_back(current);

		// If the current node is the target node then end the path
		if (EqualNodes(current, &targetNode)) {
			targetNode.parent = current->parent; // Save the target node parent (to traceback path)
			reachedTargetNode = true;
			continue;
		}

		// For all the current node neighbors add the not visited ones (not on open or closed list) and update best path
		for (auto neighbor : current->GetNeighbors()) {
			TestingTile* t = new TestingTile(neighbor); // Assert tile reference
			Node* newNeighbor = new Node(t); // Create a new node for the neighbor

			// If neighbor is not transversable or is in closed jump to next neighbor 
			if (!IsTransversable() || IsInClosed(newNeighbor)) {
				continue;
			}

			// If node is in open get node reference to update the existing node, otherwise get reference for new node
			pair<bool, Node*> result = IsInOpen(newNeighbor);
			bool neighborIsInOpen = result.first;
			Node* realNeighbor = result.second;

			// Calculate movement cost from current node to the neighbor
			int movementCost = current->gcost + realNeighbor->GetCost(); // Cost = cost from the starting node + cost of visiting the neighbor
			// If neighbor haven't been visited yet
			// Or the movement from current to the neighbor is best then the movement from another node to neighbor, update it
			if (!neighborIsInOpen || movementCost < realNeighbor->gcost) {
				// Update costs
				realNeighbor->gcost = movementCost;
				realNeighbor->hcost = HCost(realNeighbor, &targetNode);
				realNeighbor->fcost = FCost(realNeighbor);

				realNeighbor->parent = current; // Set parent to traceback path
				
				// If it's not in open add it 
				if (!neighborIsInOpen) {
					open.push_back(realNeighbor);
				}
			}
		}
	}

	// Build path by tracing back the parents from the target node until the start node
	BuildPath(&startNode, &targetNode);
	// Return path from start node to target node
	return path;
}

// Build vector with sequence of adjacent nodes from start node to target node
void Pathfinding::BuildPath(Node* startNode, Node* targetNode) {
	bool reachedStartNode = false; // Define end of sequence control
	Node* current = targetNode; // Start from the target node

	// While haven't reach the start node, keep backtracing
	while (!reachedStartNode) {
		// Add current node to the path
		TestingTile* tile = current->node;
		path.push_back(tile);

		// Check if current node is the starting node (end of path)
		if (EqualNodes(current, startNode)) {
			reachedStartNode = true;
		}
		else { // Otherwise get node parent
			current = current->parent;
		}
	}

	// Reverse path vector
	// path: targetNode - node1 - node2 - node3 - startNode
	// path: startNode - node3 - node2 - node1 - targetNode
	std::reverse(path.begin(), path.end());
}

// Check if a node is the open list and returns true/false and a node reference (to an existing node in open list or to the received node)
pair<bool, Node*> Pathfinding::IsInOpen(Node* node) {
	Node* realNode = NULL;

	for (auto openedNode : open) { // For all nodes in open list
		if (EqualNodes(node, openedNode)) { // Check if received node is this node on open list
			realNode = openedNode; // If it is save node reference
			return pair<bool, Node*>(true, realNode);
		}
	}

	// Node is not on open list, then reference the received node
	realNode = node;
	return pair<bool, Node*>(false, realNode);
}

// Check if a node is in the closed list and return true/false
bool Pathfinding::IsInClosed(Node* node) {
	for (auto closedNode : closed) { // For all nodes in closed list
		if (EqualNodes(node, closedNode)) { // Check if received node is this node in closed list
			return true;
		}
	}
	return false;
}

// Check if node is transversable (if node can be visited)
bool Pathfinding::IsTransversable() {
	return true;
}

// Check if nodeA is equal to nodeB
bool Pathfinding::EqualNodes(Node* nodeA, Node* nodeB) {
	// Check if tile position is the same
	if (nodeA->node->posX == nodeB->node->posX
		&& nodeA->node->posY == nodeB->node->posY) {
		return true;
	}
	return false;
}

// Search for node with the lowest cost in open list and return the node reference for it
Node* Pathfinding::GetNodeWithLowestCost() {
	Node* nodeWithLowestCost = NULL;
	bool firstTime = true; // Check first time
	int i = 0, index = 0; // Elements index control for open list

	// For all nodes in open list
	for (auto openedNode : open) {
		// If it's first time
		// Or node total cost is better then the lowest node total cost (lower fcost)
		// Or node total cost is equal to the lowest node total cost, but node is closer to end node (equal fcost but lower hcost)
		if (firstTime || openedNode->fcost < nodeWithLowestCost->fcost || (openedNode->fcost == nodeWithLowestCost->fcost && openedNode->hcost < nodeWithLowestCost->hcost)) {
			// Update lowest cost node reference and index
			nodeWithLowestCost = openedNode;
			index = i;
			firstTime = false;
		}
		i++;
	}

	// Remove lowest cost node from open list
	open.erase(open.begin() + index);
	// And return it
	return nodeWithLowestCost;
}

// Cost from the end node (distance)
int Pathfinding::HCost(Node* node, Node* targetNode) {
	return node->GetDistanceFrom(targetNode);
}

// Total cost for a node (gcost + hcost)
int Pathfinding::FCost(Node* node) { // Total cost
	return node->gcost + node->hcost;
}

// Destructor
Pathfinding::~Pathfinding()
{
}
