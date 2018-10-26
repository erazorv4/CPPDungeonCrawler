#include "stdafx.h"
#include "Map.h"


Map::Map()
{
	Width = 5;
	Height = 5;
}

Map::Map(int width, int height)
	: Width(width), Height(height)
{
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
}
