#pragma once
#include <string>

class Room
{
public:
	Room();
	~Room();

	//Horizontal
	int X;
	//Vertical
	int Y;
	//0 = up, 1 = right, 2 = down, 3 = left.
	Room* Rooms[4];
	int Description[3];
	bool Visited;

};

