#include <unordered_map>
#include <algorithm>
#include "ShortestPathTree.h"
#include "Dijkstra.cpp"

std::vector<std::string> ShortestPathTree::getShortestPath(interactiveMap::Map map, std::string fromRoomId, std::string toRoomId)
{
	Dijkstra djikstra;
	for (auto room : map.rooms) {
		unordered_map<std::string, int> connectionsInUnorderedMap;
		for (auto connection : room.connections)
			connectionsInUnorderedMap.insert_or_assign(connection.connectedWithId, connection.connectedRoomDistance);
		djikstra.add_vertex(room.id, connectionsInUnorderedMap);
	}
	vector<std::string> path = djikstra.shortest_path(fromRoomId, toRoomId);
	std::reverse(path.begin(), path.end());
	return path;
}

ShortestPathTree::ShortestPathTree()
{
}

ShortestPathTree::~ShortestPathTree()
{
}
