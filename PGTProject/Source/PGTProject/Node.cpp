#include "Node.h"

// Create node having a reference for a hextile and initilizing the costs
Node::Node(TestingTile* hexTile) {
	node = hexTile;
	fcost = 0;
	hcost = 0;
	gcost = 0;
}

// Get node neighbors
vector<TestingTile> Node::GetNeighbors()
{
	return node->GetNeighbours();
}

// Get cost of visiting the node
int Node::GetCost()
{
	return node->GetCost();
}

// Get distance from another node
int Node::GetDistanceFrom(Node* target)
{
	return node->GetDistanceFrom(target->node);
}

Node::~Node()
{
}
