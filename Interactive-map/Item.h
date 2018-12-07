#pragma once
#include "Node.h"
class Item : public Node
{
public:
	std::string name;
	Item(std::string name);
	~Item();
};

