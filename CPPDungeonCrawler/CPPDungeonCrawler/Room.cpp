#include "stdafx.h"
#include "Room.h"


Room::Room()
{
	
}


Room::Room(int x, int y)
	: X(x), Y(y)
{
}

Room::~Room()
{
}

Room* Room::GetAdjacentRoom(int side)
{
	return Rooms[side];
}
