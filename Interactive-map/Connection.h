#pragma once
#include "Node.h"
class Connection : public Node
{
public:
	bool leadsOutside = false;
	std::string connectedWithId;
	int connectedRoomDistance;
	Connection();
	Connection(bool leadsOutside, std::string connectedWithId, int connectedRoomDistance);
	~Connection();
};

