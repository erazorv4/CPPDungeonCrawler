#pragma once

#include <optional>
#include "Random.h"
#include "Enemy.h"
#include "Enemies.h"

class Room
{
public:
	Room();
	Room(int x, int y, int floor);
	~Room();

	Room* GetAdjacentRoom(int side);
	void GenerateContent();

	//Horizontal
	int X;
	//Vertical
	int Y;
	//0 = up, 1 = right, 2 = down, 3 = left.
	Room* Rooms[4] { NULL, NULL, NULL, NULL };
	char* Description;
	Enemies AllEnemies;
	Enemy* AvailableEnemies[4];
	Enemy* Enemies[3];
	bool Visited = true;

private:
	void CreateEnemies();
	void CreateItem();

	Random r;
	int Floor;
};

