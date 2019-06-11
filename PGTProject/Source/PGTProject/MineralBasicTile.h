#pragma once
#include "BasicTerrainTile.h"

/**
 * @brief 
 * 
 */
class MineralBasicTile final : private BasicTerrainTile
{
public:
	/**
	 * @brief Construct a new Mineral Basic Tile object
	 * 
	 * @param hex 
	 */
	MineralBasicTile(const AHexActor::Hex& hex)
		: BasicTerrainTile(hex, Minerals) {}
};
