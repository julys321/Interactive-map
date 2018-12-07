#include "Connection.h"



Connection::Connection()
{
}

Connection::Connection(bool leadsOutside, std::string connectedWithId, int connectedRoomDistance)
{
	this->leadsOutside = leadsOutside;
	leadsOutside ? this->connectedWithId = "Outside" : this->connectedWithId = connectedWithId;
	this->connectedRoomDistance = connectedRoomDistance;
}


Connection::~Connection()
{
}
