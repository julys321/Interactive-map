#include "MapLoader.h"


std::vector<Item> MapLoader::readItems(std::ifstream & input)
{
	std::vector<Item> items;
	char character;
	input.ignore(1);//ignore '{'
	int itemsCount;
	input >> itemsCount;
	input.ignore(1);//ignore ','
	for (int i = 0; i < itemsCount; i++) {
		items.push_back(readString(input));
	}
	input.ignore(2);//ignore '},'
	return items;
}

Connection MapLoader::readConnection(std::ifstream & input)
{
	Connection connection;
	int distance;
	input.ignore(1);//ignore '{'
	connection.connectedWithId = readRoomId(input);
	input >> distance;
	connection.connectedRoomDistance = distance;
	input.ignore(3);//ignore ',},'
	return connection;
}

std::vector<Connection> MapLoader::readConnections(std::ifstream & input)
{
	std::vector<Connection> connections;
	char character;
	input.ignore(1);//ignore '{'
	int connectionCount;
	input >> connectionCount;
	input.ignore(1);//ignore ','
	for (int i = 0; i < connectionCount; i++) {
		Connection connection = readConnection(input);
		connections.push_back(connection);
	}
	input.ignore(2);//ignore '},'
	return connections;
}

int MapLoader::readRoomFloor(std::ifstream & input)
{
	int floor;
	input >> floor;
	input.ignore(1);//ignore ','
	return floor;
}

std::string MapLoader::readRoomId(std::ifstream & input)
{
	std::string id;
	char character;
	while (input.get(character) && character != ',') {
		id.push_back(character);
	}
	return id;
}

Room MapLoader::readRoom(std::ifstream & input)
{
	Room room;
	char character;
	input.ignore(1);//ignore '{'
	room.id = readRoomId(input);
	room.floor = readRoomFloor(input);
	room.connections = readConnections(input);
	room.items = readItems(input);
	input.ignore(2);//ignore '},'
	return 	room;
}

std::vector<Room> MapLoader::readRooms(std::ifstream & input)
{
	std::vector<Room> rooms;
	char character;
	input.ignore(1);//ignore '{'
	int roomCount;
	input >> roomCount;
	input.ignore(1);//ignore ','
	for (int i = 0; i < roomCount; i++) {
		rooms.push_back(readRoom(input));
	}
	input.ignore(2);//ignore '},'
	return rooms;
}

std::string MapLoader::readString(std::ifstream & input)
{
	std::string name;
	char character;
	while (input.get(character) && character != ',') {
		name.push_back(character);
	}
	return name;
}

interactiveMap::Map MapLoader::loadMapFromFile(std::string fileName)
{
	interactiveMap::Map map;
	char character;
	std::ifstream input(fileName);
	input.ignore(1);//ignore '{'
	map.name = readString(input);
	map.rooms = readRooms(input);

	input.close();
	return map;
}

MapLoader::MapLoader()
{
}


MapLoader::~MapLoader()
{
}
