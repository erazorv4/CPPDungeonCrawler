#pragma once

#include "Room.h"

class Map
{
public:
	Map();
	Map(int width, int height);
	~Map();
	void Generate();
	
	int Width;
	int Height; 
	Room rooms[400];
};
