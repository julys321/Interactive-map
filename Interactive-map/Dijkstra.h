#pragma once
#include <unordered_map>
#include <vector>
#include <limits>
#include <algorithm>
#include <iostream>

using namespace std;

class Dijikstra
{
	unordered_map<std::string, const unordered_map<std::string, int>> vertices;

public:
	void add_vertex(std::string name, const unordered_map<std::string, int>& edges);
	vector<std::string> shortest_path(std::string start, std::string finish);
};