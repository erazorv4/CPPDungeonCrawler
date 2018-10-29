#pragma once

#include "Room.h"
#include "StartRoom.h"
#include "EndRoom.h"
#include <optional>

class Map
{
public:
	Map();
	Map(int width, int height);
	~Map();
	void Generate();

	void InsertRoomIntoRooms(Room room);

	int* GetSidesList(const int amountOfRooms);


	Room CheckRoomExists(int x, int y);
	
	int Width;
	int Height; 
	std::optional<Room> Rooms[400];
	StartRoom startRoom;
	EndRoom endRoom;
};
