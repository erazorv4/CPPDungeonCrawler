#pragma once
#include <string>

class Room
{
public:
	Room();
	~Room();

	int X;
	int Y;
	Room* Rooms[4];
	int Description[3];
	bool Visited;

};

