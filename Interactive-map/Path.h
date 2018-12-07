#pragma once
#include <vector>
#include "Movement.h"
class Path
{
public:
	std::vector<Movement> moves;
	Path();
	~Path();
};

