#include "Node.h"

Node::Node(TestingTile* hexTile) {
	node = hexTile;
	fcost = 0;
	hcost = 0;
	gcost = 0;
}

vector<TestingTile> Node::GetNeighbors()
{
	return node->GetNeighbours();
}

int Node::GetCost()
{
	return node->GetCost();
}

int Node::GetDistanceFrom(Node* target)
{
	return node->GetDistanceFrom(target->node);
}

Node::~Node()
{
}
