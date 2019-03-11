#pragma once

#include "HexActor.h"

class ITileObject
{
public:
	ITileObject(const AHexActor::Hex& hex, const UINT32 starCost)
		: _hex(hex),
		  _aStarCost(starCost) {}

	/**
	 * \brief 
	 * A reference to the hex tile equivalent
	 */
	AHexActor::Hex _hex;

	//TODO: add reference to HexManager

	/**
	 * \brief 
	 * The cost to enter a tile based on the A* algorithm
	 */
	const UINT32 _aStarCost;

	

};
