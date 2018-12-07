#include "Node.h"



Node::Node()
{
	this->id = this->ceateId();
}


Node::~Node()
{
}

std::string Node::ceateId()
{
	static int id = 0;
	std::string result = "#" + std::to_string(id);
	id++;
	return result;
}
