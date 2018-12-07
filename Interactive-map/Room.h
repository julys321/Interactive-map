#pragma once
#include <vector>
#include "Connection.h"
#include "Item.h"
class Room
{
public:
	std::string id;
	int floor;
	std::vector<Connection> connections;
	std::vector<Item> items;
	Room(int floor);
	Room(int floor, std::vector<Connection> connections, std::vector<Item> items);
	~Room();
private:
	std::string createId();
};

