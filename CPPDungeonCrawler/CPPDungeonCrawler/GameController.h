#pragma once
#include "Map.h"
#include "Dungeon.h"

class GameController
{
public:
	GameController();
	~GameController();

	Dungeon dungeon;
	Map currentMap;
};

