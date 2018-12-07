#pragma once
#include <vector>
#include "Room.h"
class Map
{
public:
	std::string name;
	std::vector<Room> rooms;
	Map();
	Map(std::string name , std::vector<Room> rooms);
	~Map();
};

