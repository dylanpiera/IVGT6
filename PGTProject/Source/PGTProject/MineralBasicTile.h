#pragma once
#include "BasicTerrainTile.h"

class MineralBasicTile final : private BasicTerrainTile
{
public:
	MineralBasicTile(const AHexActor::Hex& hex)
		: BasicTerrainTile(hex, Minerals) {}
};
