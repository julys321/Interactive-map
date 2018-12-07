#pragma once
#include <fstream>
#include "Map.h"
static class MapLoader
{
public:
	static std::vector<Item> readItems(std::ifstream &input);
	static std::vector<Connection> readConnections(std::ifstream &input);
	static int readRoomFloor(std::ifstream &input);
	static std::string readRoomId(std::ifstream &input);
	static Room readRoom(std::ifstream &input);
	static std::vector<Room> readRooms(std::ifstream &input);
	static std::string readString(std::ifstream &input);
	static interactiveMap::Map loadMapFromFile(std::string fileName);
	MapLoader();
	~MapLoader();
};

