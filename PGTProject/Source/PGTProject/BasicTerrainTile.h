#pragma once
#include "ITileObject.h"

class BasicTerrainTile : public ITileObject
{
public:
	BasicTerrainTile(const AHexActor::Hex& hex, const TileResource tileResource = None)
		: ITileObject(hex, 10, tileResource) {}
};
