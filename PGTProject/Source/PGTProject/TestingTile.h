#pragma once

#include "CoreMinimal.h"
#include <vector>

using std::vector;

// (UPDATE) Test class
/**
 * @brief 
 * 
 */
class TestingTile
{
public:
	int posX;	// Tile position
	int posY;
	/**
	 * @brief Get cost of visiting this tile
	 * 
	 * @return int 
	 */
	int GetCost();	
	/**
	 * @brief Get the Neighbours object
	 * 
	 * @return * vector<TestingTile> 
	 */
	vector<TestingTile> GetNeighbours();
	/**
	 * @brief Get distance between this tile and a received tile (other)
	 * 
	 * @param other 
	 * @return int 
	 */
	int GetDistanceFrom(TestingTile* other);	// 
	/**
	 * @brief Construct a new Testing Tile object
	 * 
	 * @param x 
	 * @param y 
	 */
	TestingTile(int x, int y);
	/**
	 * @brief Destroy the Testing Tile object
	 * 
	 */
	~TestingTile();
};

