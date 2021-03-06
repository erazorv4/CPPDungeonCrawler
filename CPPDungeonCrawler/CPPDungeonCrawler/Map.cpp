#include "stdafx.h"
#include "Map.h"
#include "Random.h"
#include "Room.h"
#include <iostream>
#include "ArrayHelper.h"
#include "GameController.h"
#include "Directions.h"

Map::Map()
{
}

Map::Map(int width, int height, int floor)
	: Width(width), Height(height), Floor(floor)
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

	int startingX = 5;//r.Generate(1, Width);
	int startingY = 5;//r.Generate(1, Height);
	int currentX = startingX;
	int currentY = startingY;

	Room startRoom = Room(startingX, startingY, Floor);
	Rooms[0] = startRoom;

	int amountOfRooms = 4;//r.Generate(1, 4);
	Directions::Direction* sidesList = GetSidesList(amountOfRooms, startRoom);

	for (int i = 0; i < amountOfRooms; i++)
	{
		currentX = startRoom.X;
		currentY = startRoom.Y;
		switch (static_cast<int>(sidesList[i]))
		{
		case 0:
			currentY = startRoom.Y - 1;
			break;
		case 1:
			currentX = startRoom.X + 1;
			break;
		case 2:
			currentY = startRoom.Y + 1;
			break;
		case 3:
			currentX = startRoom.X - 1;
			break;
		default:
			break;
		}
		Room* nextRoom = new Room(currentX, currentY, Floor);
		nextRoom->Rooms[Directions::ReverseDirection(sidesList[i])] = &startRoom;
		startRoom.Rooms[sidesList[i]] = nextRoom;
		InsertRoomIntoRooms(*nextRoom);
	}

	Rooms[0] = startRoom;

	// main generation loop
	for (int i = 1; i < Width * Height; i++)
	{
		if (!Rooms[i])
		{
			return;
		}
		int amountOfRooms = r.Generate(0, 3);
		Directions::Direction* sidesList = GetSidesList(amountOfRooms, Rooms[i].value());
		currentX = Rooms[i].value().X;
		currentY = Rooms[i].value().Y;
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
				currentX = Rooms[i].value().X - 1;
				break;
			default:
				break;
			}
			Room* nextRoom = CheckRoomExists(currentX, currentY);
			if (nextRoom->X != 0 && nextRoom->Y != 0)
			{
				nextRoom->Rooms[Directions::ReverseDirection(sidesList[i])] = &Rooms[i].value();
				Rooms[i].value().Rooms[sidesList[t]] = nextRoom;
			}
			else
			{
				nextRoom = new Room(currentX, currentY, Floor);
				nextRoom->Rooms[Directions::ReverseDirection(sidesList[i])] = &Rooms[i].value();
				Rooms[i].value().Rooms[sidesList[t]] = nextRoom;
				InsertRoomIntoRooms(*nextRoom);
			}
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

Directions::Direction* Map::GetSidesList(int &amountOfRooms, Room currentRoom)
{
	Random r = Random();
	Directions::Direction sidesList[4] = { Directions::Direction::None, Directions::Direction::None, Directions::Direction::None, Directions::Direction::None };
	Directions::Direction dissallowedSidesList[2] = { Directions::Direction::None, Directions::Direction::None };

	if (currentRoom.X <= 1)
	{
		dissallowedSidesList[0] = Directions::Direction::Left;
		if (amountOfRooms >= 3)
		{
			amountOfRooms = amountOfRooms - 1;
		}
	}
	else if (currentRoom.X >= Width)
	{
		dissallowedSidesList[0] = Directions::Direction::Right;
		if (amountOfRooms >= 3)
		{
			amountOfRooms--;
		}
	}
	if (currentRoom.Y <= 1)
	{
		dissallowedSidesList[1] = Directions::Direction::Up;
		if (amountOfRooms >= 2)
		{
			amountOfRooms--;
		}
	}
	else if (currentRoom.Y >= Height)
	{
		dissallowedSidesList[1] = Directions::Direction::Down;
		if (amountOfRooms >= 2)
		{
			amountOfRooms--;
		}
	}

	for (int i = 0; i < amountOfRooms; i++)
	{
		// decide where to place room.
		Directions::Direction sideToPlaceRoom = Directions::Direction::None;
		while (sideToPlaceRoom == Directions::Direction::None || ArrayHelper().CheckArrayContainsElement(sideToPlaceRoom, sidesList) || ArrayHelper().CheckArrayContainsElement(sideToPlaceRoom, dissallowedSidesList))
		{
			sideToPlaceRoom = static_cast<Directions::Direction>(r.Generate(0, 3));
		}
		sidesList[i] = (Directions::Direction)sideToPlaceRoom;
	}
	return sidesList;
}

Room Map::GetStartRoom()
{
	return Rooms[0].value();
}

Room* Map::CheckRoomExists(int x, int y)
{
	if (x < 1 || x > Width)
	{
		return new Room(0, 0, Floor);
	}
	if (y < 1 || y > Height)
	{
		return new Room(0, 0, Floor);
	}

	for (int i = 0; i < Width * Height; i++)
	{
		if (Rooms[i])
		{
			if (Rooms[i].value().X == x && Rooms[i].value().Y == y)
			{
				return &Rooms[i].value();
			}
		}
		else
		{
			return new Room(0, 0, Floor);
		}
	}
	return new Room(0, 0, Floor);
}
