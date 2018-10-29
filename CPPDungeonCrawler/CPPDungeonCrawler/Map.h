#pragma once

#include "Room.h"
#include <optional>

class Map
{
public:
	Map();
	Map(int width, int height);
	~Map();
	void Generate();

	void InsertRoomIntoRooms(Room room);

	int* GetSidesList(int &amountOfRooms, Room currentRoom);
	Room GetStartRoom();

	 
	Room* CheckRoomExists(int x, int y);
	
	int Width;
	int Height; 
	std::optional<Room> Rooms[400];
};
