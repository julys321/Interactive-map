#include "MapSaver.h"



void MapSaver::writeItems(std::ofstream & output, std::vector<Item> items)
{
	output << '{' << items.size() << ',';
	for (Item item : items) {
		writeString(output, item.name);
	}
	output << "},";
}

void MapSaver::writeConnection(std::ofstream & output, Connection connection)
{
	output << '{';
	writeString(output, connection.connectedWithId);
	output << connection.metreDistanceFromRoomCenter << ',';
	output << "},";
}

void MapSaver::writeConnections(std::ofstream & output, std::vector<Connection> connections)
{
	output << '{' << connections.size() << ',';
	for (Connection connection : connections) {
		writeConnection(output, connection);
	}
	output << "},";
}

void MapSaver::writeRoom(std::ofstream & output, Room room)
{
	output << "{" << room.id << ',' << room.floor << ',';
	writeConnections(output,room.connections);
	writeItems(output,room.items);
	output << "},";
}

void MapSaver::writeRooms(std::ofstream & output, std::vector<Room> rooms)
{
	output << '{' << rooms.size() << ',';
	for (Room room: rooms) {
		writeRoom(output, room);
	}
	output << "},";
}

void MapSaver::writeString(std::ofstream & output, std::string string)
{
	output << string << ',';
}

void MapSaver::writeMapToFile(std::string fileName, interactiveMap::Map map)
{
	std::ofstream output(fileName);
	output << '{';
	writeString(output, map.name);
	writeRooms(output, map.rooms);
	output << "}";
	output.close();
}

MapSaver::MapSaver()
{
}


MapSaver::~MapSaver()
{
}
