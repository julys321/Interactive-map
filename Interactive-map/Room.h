#pragma once
#include <vector>
#include "Connection.h"
#include "Item.h"
class Room
{
public:
	std::vector<Connection> connections;
	std::vector<Item> items;
	Room();
	~Room();
};

