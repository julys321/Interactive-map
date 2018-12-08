#include <unordered_map>
#include <vector>
#include <limits>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Dijkstra
{
	unordered_map<std::string, unordered_map<std::string, int>> vertices;

public:
	void add_vertex(std::string name, unordered_map<std::string, int>& edges)
	{
		// Insert the connected nodes in unordered map
		vertices.insert(unordered_map<std::string, unordered_map<std::string, int>>::value_type(name, edges));
	}

	vector<std::string> shortest_path(std::string start, std::string finish)
	{
		// Second arguments -> distances
		// Find the smallest distance in the already in closed list and push it in -> previous
		unordered_map<std::string, int> distances;
		unordered_map<std::string, std::string> previous;
		vector<std::string> nodes; // Open list
		vector<std::string> path; // Closed list

		auto comparator = [&](std::string left, std::string right) { return distances[left] > distances[right]; };

		for (auto& vertex : vertices)
		{
			if (vertex.first == start)
			{
				distances[vertex.first] = 0;
			}
			else
			{
				distances[vertex.first] = numeric_limits<int>::max();
			}

			nodes.push_back(vertex.first);
			push_heap(begin(nodes), end(nodes), comparator);
		}

		while (!nodes.empty())
		{
			pop_heap(begin(nodes), end(nodes), comparator);
			std::string smallest = nodes.back();
			nodes.pop_back();

			//std::cout << "Open list: ";
			//for (std::vector<std::string>::const_iterator i = nodes.begin(); i != nodes.end(); ++i)
			//	std::cout << *i << ' ';
			//std::cout << std::endl;

			if (smallest == finish)
			{
				while (previous.find(smallest) != end(previous))
				{
					path.push_back(smallest);
					smallest = previous[smallest];
					//std::cout << "Closed list: ";
					//for (std::vector<std::string>::const_iterator i = path.begin(); i != path.end(); ++i)
					//	std::cout << *i << ' ';
					//std::cout << std::endl;
				}

				break;
			}

			if (distances[smallest] == numeric_limits<int>::max())
			{
				break;
			}

			for (auto& neighbor : vertices[smallest])
			{
				int alt = distances[smallest] + neighbor.second;
				if (alt < distances[neighbor.first])
				{
					distances[neighbor.first] = alt;
					previous[neighbor.first] = smallest;
					make_heap(begin(nodes), end(nodes), comparator);
				}
			}
		}

		return path;
	}
};