#include "Node.h"



Node::Node()
{
	static int id = 0;
	this->id = "#" + std::to_string(id);
	id++;
}


Node::~Node()
{
}
