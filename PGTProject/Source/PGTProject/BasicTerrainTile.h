#pragma once
#include "ITileObject.h"

/**
 * @brief 
 * 
 */
class BasicTerrainTile : public ITileObject
{
public:
	/**
	 * @brief Construct a new Basic Terrain Tile object
	 * 
	 * @param hex 
	 * @param tileResource 
	 */
	BasicTerrainTile(const AHexActor::Hex& hex, const TileResource tileResource = None)
		: ITileObject(hex, 10, tileResource) {}
};
