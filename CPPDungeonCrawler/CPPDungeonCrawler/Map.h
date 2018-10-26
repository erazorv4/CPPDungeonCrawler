#pragma once

#include "Room.h"

class Map
{
public:
	Map();
	~Map();
	
	int Height;
	int Width;
	Room rooms[400];
};
