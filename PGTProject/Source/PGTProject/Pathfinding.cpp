// Fill out your copyright notice in the Description page of Project Settings.

#include "Pathfinding.h"
#include <GraphAStar.h>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;

class FNodeRef {
public:
	int nodeId;
	vector<pair<FNodeRef, int>> neighbours;

	FNodeRef(int id) {
		this->nodeId = id;
	}

	void AddNeighbour(FNodeRef next, int edgeCost) {
		this->neighbours.push_back(pair<FNodeRef, int>(next, edgeCost));
	}
};


class FMyTGraph {
	//Needs to implement functions: int32 GetNeighbourCount(FNodeRef NodeRef) const; - returns number of neighbours that the graph node identified with NodeRef has bool IsValidRef(FNodeRef NodeRef) const; - returns whether given node identyfication is correct FNodeRef GetNeighbour(const FNodeRef NodeRef, const int32 NeighbourIndex) const; - returns neighbour ref
	//it also needs to specify node type FNodeRef - type used as identification of nodes in the graph
	int32 GetNeighbourCount(FNodeRef NodeRef) const;
	FNodeRef GetNeighbour(const FNodeRef NodeRef, const int32 NeighbourIndex) const;

	int32 GetNeighbourCount(FNodeRef NodeRef) const {
		return NodeRef.neighbours.size();
	}

	FNodeRef GetNeighbour(const FNodeRef NodeRef, const int32 NeighbourIndex) const {
		return NodeRef.neighbours[NeighbourIndex].first;
	}
};

class FMyTQueryFilter {
	/*TQueryFilter (FindPath's parameter) filter class is what decides which graph edges can be used and at what cost. It needs to implement following functions: float GetHeuristicScale() const; - used as GetHeuristicCost's multiplier float GetHeuristicCost(const FNodeRef StartNodeRef, const FNodeRef EndNodeRef) const; - estimate of cost from StartNodeRef to EndNodeRef float GetTraversalCost(const FNodeRef StartNodeRef, const FNodeRef EndNodeRef) const; - real cost of traveling from StartNodeRef directly to EndNodeRef bool IsTraversalAllowed(const FNodeRef NodeA, const FNodeRef NodeB) const; - whether traversing given edge is allowed bool WantsPartialSolution() const; - whether to accept solutions that do not reach the goal*/
	float GetHeuristicScale() const;
	float GetHeuristicCost(const FNodeRef StartNodeRef, const FNodeRef EndNodeRef) const;
	float GetTraversalCost(const FNodeRef StartNodeRef, const FNodeRef EndNodeRef) const;
	bool IsTraversalAllowed(const FNodeRef NodeA, const FNodeRef NodeB) const;
	bool WantsPartialSolution() const;

	float GetHeuristicScale() const {
		return 1.0;
	}

	float GetHeuristicCost(const FNodeRef StartNodeRef, const FNodeRef EndNodeRef) const {
		FNodeRef currentNode = StartNodeRef;
		vector<int> visited;

		while (currentNode.nodeId != EndNodeRef.nodeId) {
			pair<FNodeRef, int> minimumCostNode;
			bool firstTime = true;

			for (auto node : currentNode.neighbours) {
				bool alreadyVisited = false;
				for (auto visitedNode : visited) {
					if (visitedNode == currentNode.nodeId) {
						alreadyVisited = true;
						break;
					}
				}

				if (!alreadyVisited) {
					int edgeCost = node.second;
					int minimumCost = minimumCostNode.second;
					if (firstTime || edgeCost < minimumCost) {
						minimumCostNode = node;
						firstTime = false;
					}
				}
			}
			
			currentNode = minimumCostNode.first;
		}
	}

	float GetTraversalCost(const FNodeRef StartNodeRef, const FNodeRef EndNodeRef) const {
		return GetHeuristicCost(StartNodeRef, EndNodeRef);
	}

	bool IsTraversalAllowed(const FNodeRef NodeA, const FNodeRef NodeB) const {
		return true;
	}

	bool WantsPartialSolution() const {
		return true;
	}
};


// Constructor
Pathfinding::Pathfinding()
{
	TArray<FNodeRef> OutPath;
	FGraphAStar<FMyTGraph> Pathfinder(FMyTQueryFilter) = new FMyTQueryFilter();
	FNodeRef a = FNodeRef(1);
	FNodeRef b = FNodeRef(2);
	a.AddNeighbour(b, 5);
	b.AddNeighbour(a, 5);

	Pathfinder.FindPath(a, b, FMyTQueryFilter, OutPath);
}

Pathfinding::~Pathfinding()
{
}
