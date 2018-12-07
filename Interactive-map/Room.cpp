#include "Room.h"



Room::Room(int floor)
{
	this->floor = floor;
	this->id = this->createId();
}

Room::Room(int floor, std::vector<Connection> connections, std::vector<Item> items)
{
	this->floor = floor;
	this->id = this->createId();
	this->connections = connections;
	this->items = items;
}


Room::~Room()
{
}

std::string Room::createId()
{
	static int id = 0;
	std::string result = "0" + std::to_string(id);
	id++;
	result.erase(result.begin(), result.end() - 2);
	return std::to_string(this->floor) + result;
}
