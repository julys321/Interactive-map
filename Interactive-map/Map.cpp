#include "Map.h"



Map::Map()
{
}

Map::Map(std::string name, std::vector<Room> rooms)
{
	this->name = name;
	for (Room room : rooms) {
		this->rooms.push_back(room);
	}
}


Map::~Map()
{
}
