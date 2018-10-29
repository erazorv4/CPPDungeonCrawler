#pragma once

#include "Room.h"
#include <optional>
#include "Directions.h"

class Map
{
public:
	Map();
	Map(int width, int height, int floor);
	~Map();
	void Generate();

	void InsertRoomIntoRooms(Room room);

	Directions::Direction* GetSidesList(int &amountOfRooms, Room currentRoom);
	Room GetStartRoom();

	 
	Room* CheckRoomExists(int x, int y);
	
	int Width;
	int Height;
	int Floor;
	std::optional<Room> Rooms[400];
};
