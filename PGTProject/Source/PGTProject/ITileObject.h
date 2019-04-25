#pragma once

#include "HexActor.h"
#include "EconomyManager.h"
#include <algorithm>

class ITileObject
{
public:
	virtual ~ITileObject();

	/**
	 * \brief
	 * A reference to the hex tile equivalent
	 */
	const AHexActor::Hex& _hex;

	//TODO: add pointer to HexManager

	/**
	 * \brief
	 * The cost to enter a tile based on the A* algorithm
	 * Base cost: 10
	 */
	const UINT32 _aStarCost;

	/**
	 * \brief
	 * (global) constraint, is this tile in current play area aka buildable?
	 */
	bool _buildable;

	/**
	 * \brief
	 * Amount of road created by actors moving over the tile
	 */
	float _roadPercentage;

	UINT32 CalculateRoadCost() const
	{
		return std::min(int(floor(_aStarCost - (_aStarCost * _roadPercentage))),1);
	}

	#pragma region Resources
	EconomyManager::Resources _resources;

	/**
	 * \brief
	 * Updates the supplied parameter with the resource output from this tile.
	 * \param resources
	 */
	virtual void UpdateResources(EconomyManager::Resources &resources)
	{
		resources._energy += this->_resources._energy;
		resources._materials += this->_resources._materials;
		resources._money += this->_resources._money;
	}
#pragma endregion

	#pragma region TileResources

	/**
	 * \brief
	 * Indicates if a certain tile contains a resource
	 */
	enum TileResource
	{
		None,
		Minerals
	};

	TileResource _tileResource;
#pragma endregion 

	ITileObject(const AHexActor::Hex& hex, const UINT32 starCost, const bool buildable = true, const TileResource tileResource = None)
		: _hex(hex),
		_aStarCost(starCost), _buildable(buildable), _roadPercentage(0), _tileResource(tileResource) {}
};
