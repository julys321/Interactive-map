#pragma once
#include "Map.h"
class ShortestPathTree
{
public:
	static std::vector<std::string> getShortestPath(interactiveMap::Map map, std::string fromRoomId, std::string toRoomId);
	ShortestPathTree();
	~ShortestPathTree();
};

