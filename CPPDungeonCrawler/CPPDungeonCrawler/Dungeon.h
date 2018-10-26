#pragma once

#include "Map.h"

class Dungeon
{
public:
	Dungeon();
	~Dungeon();
	int Depth;
	Map maps[5];
};

