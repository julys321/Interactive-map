#pragma once
#include <fstream>
#include "Map.h"
class MapSaver
{
public:
	static void writeMapToFile(std::string fileName, interactiveMap::Map map);
	MapSaver();
	~MapSaver();
private:
	static void writeItems(std::ofstream &output, std::vector<Item> items);
	static void writeConnections(std::ofstream &output, std::vector<Connection> connections);
	static void writeRoom(std::ofstream &output, Room room);
	static void writeRooms(std::ofstream &output, std::vector<Room> rooms);
	static void writeString(std::ofstream &output, std::string string);
};

