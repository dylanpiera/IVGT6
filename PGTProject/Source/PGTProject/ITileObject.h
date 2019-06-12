#pragma once

#include "HexActor.h"
#include "EconomyManager.h"
#include <algorithm>

/**
 * @brief Storage container for non-coordinate based hex details.
 * 
 * Contains non-coordinate details of the hex, like the AStar Cost to enter the tile, or what mineral is on it.
 */
class ITileObject
{
public:
	/**
	 * @brief Destroy the ITileObject object
	 * 
	 */
	virtual ~ITileObject();

	/**
	 * @brief A reference to the hex tile equivalent
	 * 
	 */
	const AHexActor::Hex& _hex;

	//TODO: add pointer to HexManager

	/**
	 * @brief The cost to enter a tile based on the A* algorithm
	 * Base cost: 10
	 */
	const UINT32 _aStarCost;

	/**
	 * @brief (global) constraint, is this tile in current play area aka buildable?
	 * 
	 */
	bool _buildable;

	/**
	 * @brief Amount of road created by actors moving over the tile
	 * 
	 */
	float _roadPercentage;

	/**
	 * @brief Calculates the aStar cost based on the road percentage.
	 * 
	 * @return UINT32 Cost
	 */
	UINT32 CalculateRoadCost() const
	{
		return std::min(int(floor(_aStarCost - (_aStarCost * _roadPercentage))),1);
	}

	#pragma region Resources
	EconomyManager::Resources _resources;

	/**
	 * @brief [OBSOLETE] Updates the supplied parameter with the resource output from this tile.
	 * 
	 * @param resources 
	 */
	virtual void UpdateResources(EconomyManager::Resources &resources)
	{
		resources._energy += this->_resources._energy;
		resources._minerals += this->_resources._minerals;
		resources._money += this->_resources._money;
	}
#pragma endregion

	#pragma region TileResources

	/**
	 * @brief Indicates if a certain tile contains a resource
	 * 
	 */
	enum TileResource
	{
		None,
		Minerals
	};

	TileResource _tileResource;
#pragma endregion 

	/**
	 * @brief Construct a new ITileObject object
	 * 
	 * @param hex 
	 * @param starCost 
	 * @param buildable 
	 * @param tileResource 
	 */
	ITileObject(const AHexActor::Hex& hex, const bool buildable = true, const TileResource tileResource = None)
		: _hex(hex), _buildable(buildable), _roadPercentage(0), _tileResource(tileResource)
		{
			_aStarCost = _hex->_aStarCost;
		}
};
