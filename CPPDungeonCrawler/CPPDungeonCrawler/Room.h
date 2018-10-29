#pragma once

#include <optional>

class Room
{
public:
	Room();
	Room(int x, int y);
	~Room();

	Room* GetAdjacentRoom(int side);

	//Horizontal
	int X;
	//Vertical
	int Y;
	//0 = up, 1 = right, 2 = down, 3 = left.
	Room* Rooms[4] { NULL, NULL, NULL, NULL };
	int Description[3];
	bool Visited = true;

};

