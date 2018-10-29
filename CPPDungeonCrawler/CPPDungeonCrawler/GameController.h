#pragma once
#include "Map.h"
#include "Dungeon.h"
#include "Hero.h"

class GameController
{
public:
	GameController();
	~GameController();

	void DisplayMap();
	void MoveHero(int Direction);

	Dungeon dungeon;
	Map* currentMap;
	Hero hero;
	int Width;
	int Height;
	bool GameIsRunning = true;
};

