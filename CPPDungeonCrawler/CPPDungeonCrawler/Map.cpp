#include "stdafx.h"
#include "Map.h"
#include "Random.h"
#include "Room.h"
#include "StartRoom.h"
#include "EndRoom.h"
#include <iostream>
#include "ArrayHelper.h"


Map::Map()
{
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
	int currentX = startingX;
	int currentY = startingY;

	startRoom = StartRoom(startingX, startingY);
	Rooms[0] = startRoom;

	int amountOfRooms = r.Generate(1, 4);
	int* sidesList = GetSidesList(amountOfRooms);

	for (int i = 0; i < amountOfRooms; i++)
	{
		switch (sidesList[i])
		{
		case 0:
			currentY = Rooms[0].value().Y - 1;
			break;
		case 1:
			currentX = Rooms[0].value().X + 1;
			break;
		case 2:
			currentY = Rooms[0].value().Y + 1;
			break;
		case 3:
			currentX = Rooms[0].value().Y - 1;
			break;
		}
		Room nextRoom = Room(currentX, currentY);
		Rooms[0].value().Rooms[sidesList[i]] = &nextRoom;
		InsertRoomIntoRooms(nextRoom);
	}
	

	// main generation loop
	for (int i = 1; i < Width * Height; i++)
	{
		int amountOfRooms = r.Generate(0, 3);
		int* sidesList = GetSidesList(amountOfRooms);

		// Generate Rooms
		for (int t = 0; t < amountOfRooms; t++)
		{
			switch (sidesList[t])
			{
			case 0:
				currentY = Rooms[i].value().Y - 1;
				break;
			case 1:
				currentX = Rooms[i].value().X + 1;
				break;
			case 2:
				currentY = Rooms[i].value().Y + 1;
				break;
			case 3:
				currentX = Rooms[i].value().Y - 1;
				break;
			}
			Room nextRoom = CheckRoomExists(currentX, currentY);
			if (nextRoom.X != 0 && nextRoom.Y != 0)
			{
				Rooms[i].value().Rooms[sidesList[t]] = &nextRoom;
			}
			else
			{
				nextRoom = Room(currentX, currentY);
				Rooms[i].value().Rooms[sidesList[t]] = &nextRoom;
			}
			InsertRoomIntoRooms(nextRoom);
		}

	}
	std::cout << "Done Generating";
}

void Map::InsertRoomIntoRooms(Room room)
{
	for (int i = 0; i < Width * Height; i++)
	{
		if (!Rooms[i])
		{
			Rooms[i] = room;
			return;
		}
	}
}

int* Map::GetSidesList(const int amountOfRooms)
{
	Random r = Random();
	int sidesList[4] = { -1, -1, -1, -1 };
	for (int i = 0; i < amountOfRooms; i++)
	{
		// decide where to place room.
		//TODO Check for bounds.
		int sideToPlaceRoom = -1;
		while (sideToPlaceRoom == -1 || ArrayHelper().CheckArrayContainsElement(sideToPlaceRoom, sidesList))
		{
			sideToPlaceRoom = r.Generate(0, 3);
		}
		sidesList[i] = sideToPlaceRoom;
	}
	return sidesList;
}

Room Map::CheckRoomExists(int x, int y)
{
	//HACK uncomment later.
	/*if (x < 1 || x > Width)
	{
		std::cerr << "x is not within bounds in CheckRoomExists." << std::endl << "x: " << x << std::endl << "Width: " << Width;
		return Room(0, 0);
	}
	if (y < 1 || y > Height)
	{
		std::cerr << "y is not within bounds in CheckRoomExists." << std::endl << "y: " << y << std::endl << "Height: " << Height;
		return Room(0, 0);
	}*/
	for (int i = 0; i < Width * Height; i++)
	{
		if (Rooms[i])
		{
			if (Rooms[i].value().X == x && Rooms[i].value().Y == y)
			{
				return Rooms[i].value();
			}
		}
		else
		{
			return Room(0, 0);
		}
	}
	return Room(0, 0);
}

