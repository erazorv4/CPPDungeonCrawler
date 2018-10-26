#include "stdafx.h"
#include "Map.h"
#include "Random.h"
#include "Room.h"
#include "StartRoom.h"
#include "EndRoom.h"
#include <iostream>


Map::Map()
{
	Width = 5;
	Height = 5;
	Generate();
}

Map::Map(int width, int height)
	: Width(width), Height(height)
{
	Generate();
}

Map::~Map()
{
}

void Map::Generate()
{
	//TODO Generate map.

	// pak een random x en y. daar zet je de start. dan generate je 1 - 4 rooms daaraan.
	// en dan ga je voor elke room elke keer weer 1 - 3 andere rooms generaten.
	// behalve als er al een room daar zit. dan generate je hem niet maar plaats je een 'hallway'/slaat de room op in currentRoom.
	// Zorg dat de rooms ook binnen de width en height blijven.
	// na minimaal 5 stappen ofzo een endroom generaten. en als die gegenerate is niet meer een andere gennen.
	// het moment dat er een endroom is 0 - 3 rooms.

	Random r = Random();

	int startingX = r.Generate(1, Width);
	int startingY = r.Generate(1, Height);

	startRoom = StartRoom(startingX, startingY);
	Rooms[0] = startRoom;
	for (int i = 0; i < Width * Height; i++)
	{
		
	}
}

Room Map::CheckRoomExists(int x, int y)
{
	if (x < 1 || x > Width)
	{
		std::cerr << "y is not within bounds in CheckRoomExists." << std::endl << "x: " << x << std::endl << "Width: " << Width;
		return;
	}
	if (y < 1 || y > Height)
	{
		std::cerr << "y is not within bounds in CheckRoomExists." << std::endl << "y: " << y << std::endl << "Height: " << Height;
		return;
	}
	for (int i = 0; i < Width * Height; i++)
	{
		if (Rooms[i])
		{

		}
	}
}
