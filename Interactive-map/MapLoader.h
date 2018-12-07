#pragma once
#include "Map.h"
class MapLoader
{
public:
	static interactiveMap::Map loadMapFromFile();
	MapLoader();
	~MapLoader();
};

