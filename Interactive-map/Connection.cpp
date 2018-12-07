#include "Connection.h"



Connection::Connection()
{
}

Connection::Connection(bool leadsOutside, std::string connectedWithId)
{
	this->leadsOutside = leadsOutside;
	leadsOutside ? this->connectedWithId = "Outside" : this->connectedWithId = connectedWithId;
}


Connection::~Connection()
{
}
