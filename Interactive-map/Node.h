#pragma once
#include <string>
class Node
{
public:
	std::string id;
	int metreDistanceFromRoomCenter = 1;
	Node();
	~Node();
private:
	std::string ceateId();
};

