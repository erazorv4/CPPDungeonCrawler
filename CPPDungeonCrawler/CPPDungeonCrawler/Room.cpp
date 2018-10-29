#include "stdafx.h"
#include "Room.h"
#include "RoomDescriptions.h"
#include "Random.h"
#include "Enemies.h"

Room::Room()
{
	
}

Room::Room(int x, int y, int floor)
	: X(x), Y(y), Floor(floor)
{
	r = Random();

	AllEnemies = ::Enemies();

	if (Floor == 1)
	{
		AvailableEnemies[0] = AllEnemies.EnemyList[0];

		// AvailableEnemies[0] = Enemies::EnemyList[0];
		// AvailableEnemies[1] = Enemies::EnemyList[1];
		// AvailableEnemies[2] = Enemies::EnemyList[2];
		// AvailableEnemies[3] = Enemies::EnemyList[3];
	}
	else if (Floor == 2)
	{
		// AvailableEnemies[0] = Enemies::EnemyList[4];
		// AvailableEnemies[1] = Enemies::EnemyList[5];
		// AvailableEnemies[2] = Enemies::EnemyList[6];
		// AvailableEnemies[3] = Enemies::EnemyList[7];
	}
	else if (Floor == 3)
	{
		// AvailableEnemies[0] = Enemies::EnemyList[8];
		// AvailableEnemies[1] = Enemies::EnemyList[9];
		// AvailableEnemies[2] = Enemies::EnemyList[10];
		// AvailableEnemies[3] = Enemies::EnemyList[11];
	}
	// Description = RoomDescriptions::GetRandomDescription();
}

Room::~Room()
{
}

Room* Room::GetAdjacentRoom(int side)
{
	return Rooms[side];
}

void Room::GenerateContent()
{
	CreateEnemies();
	CreateItem();
}

void Room::CreateEnemies()
{
	// 20% chance to generate an enemy
	const int hasEnemies = r.Generate(0, 4);

	if (hasEnemies == 2)
	{
		// 20% chance for room to have more than 1 enemy
		const int multipleEnemiesChance = r.Generate(0, 4);

		int amountOfEnemies = 1;

		if (multipleEnemiesChance == 2)
		{
			// max 3 enemies in a room
			 amountOfEnemies = r.Generate(1, 3);
		}

		for (int i = 1; i <= amountOfEnemies; i++)
		{
			const int randomEnemyPicker = r.Generate(0, 3);
			Enemies[i] = AvailableEnemies[randomEnemyPicker];
		}
	}
}

void Room::CreateItem()
{
}