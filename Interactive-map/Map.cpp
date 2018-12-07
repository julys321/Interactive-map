#include "Map.h"
using namespace interactiveMap;


Map::Map()
{
}

Map::Map(std::string name, std::vector<Room> rooms)
{
	this->name = name;
	this->rooms = rooms;
}


Map::~Map()
{
}
