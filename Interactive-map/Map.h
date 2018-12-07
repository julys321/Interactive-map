#pragma once
#include <vector>
#include "Room.h"
namespace interactiveMap { class Map; };
class interactiveMap::Map
{
public:
	std::string name;
	std::vector<Room> rooms;
	Map();
	Map(std::string name , std::vector<Room> rooms);
	~Map();
};

