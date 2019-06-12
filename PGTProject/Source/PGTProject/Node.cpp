#include "Node.h"
#include "Kismet/GameplayStatics.h"
#include "HexGridManager.h"
#include "HexActor.h"

// Create node having a reference for a hextile and initilizing the costs
Node::Node(AHexActor* hexTile) {
	HexTile = hexTile;
	FCost = 0;
	HCost = 0;
	GCost = 0;

	FindHexGridManager();
}

// Get node neighbors
vector<AHexActor*> Node::GetNeighbors()
{
	vector<AHexActor*> neighbors; // Neighbors list

	// For all directions from center hex
	for(int i = 0; i < 6; i++)
	{
		// Find neighbor
		AHexActor::Hex neighbor_hex = HexTile->hex_neighbor(*(HexTile->hex), i);
		AHexActor* neighbor = _hexGridManager->GetHexActorFromHex(neighbor_hex);

		// If neighbor was found, push it to the neighbors list
		if (neighbor != NULL) {
			neighbors.push_back(neighbor);
		}
	}
	
	return neighbors;
}

// Get cost of visiting the node
int Node::GetCost()
{
	return HexTile->_aStarCost;
}

// Get distance from another node
int Node::GetDistanceFrom(Node* target)
{
	return HexTile->hex_distance(*(HexTile->hex), *(target->HexTile->hex));
}

Node::~Node()
{
}

// Get reference to HexGridManager
void Node::FindHexGridManager() {
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GWorld,
		AHexGridManager::StaticClass(),
		FoundActors);
	if (FoundActors.Num() > 0) {
		_hexGridManager = Cast<AHexGridManager>(FoundActors[0]);
	}
}

// Check if two nodes reference the same HexActor
bool Node::EqualNodes(Node* other)
{
	return HexTile->hex_equal(*(HexTile->hex), *(other->HexTile->hex));
}