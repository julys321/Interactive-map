#pragma once
#include "Map.h"
class MapLoader
{
public:
	static interactiveMap::Map loadMapFromJson();
	MapLoader();
	~MapLoader();
};

