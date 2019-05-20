#include "Node.h"

// Create node having a reference for a hextile and initilizing the costs
Node::Node(TestingTile* hexTile) {
	HexTile = hexTile;
	FCost = 0;
	HCost = 0;
	GCost = 0;
}

// Get node neighbors
vector<TestingTile> Node::GetNeighbors()
{
	return HexTile->GetNeighbours();
}

// Get cost of visiting the node
int Node::GetCost()
{
	return HexTile->GetCost();
}

// Get distance from another node
int Node::GetDistanceFrom(Node* target)
{
	return HexTile->GetDistanceFrom(target->HexTile);
}

Node::~Node()
{
}
