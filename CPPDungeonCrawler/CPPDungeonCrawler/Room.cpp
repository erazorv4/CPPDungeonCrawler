#include "stdafx.h"
#include "Room.h"
#include "RoomDescriptions.h"


Room::Room()
{
	
}


Room::Room(int x, int y)
	: X(x), Y(y)
{
	//Description = RoomDescriptions::GetRandomDescription();
}

Room::~Room()
{
}

Room* Room::GetAdjacentRoom(int side)
{
	return Rooms[side];
}
