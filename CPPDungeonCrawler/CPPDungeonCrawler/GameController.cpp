#include "stdafx.h"
#include "GameController.h"
#include <iostream>


GameController::GameController()
{
	currentMap = new Map(10, 10, 1);
	hero.X = currentMap->GetStartRoom().X;
	hero.Y = currentMap->GetStartRoom().Y;
	hero.CurrentRoom = currentMap->GetStartRoom();
	DisplayMap();

}


GameController::~GameController()
{
	delete currentMap;
}

void GameController::DisplayMap()
{
	//TODO improve this.
	std::cout << std::endl;
	std::cout << " ----------" << std::endl;
	for (int y = 1; y <= currentMap->Height; y++)
	{
		std::cout << "|";
		for (int x = 1; x <= currentMap->Width; x++)
		{
			Room currentRoom = *currentMap->CheckRoomExists(x, y);
			if (currentRoom.X != 0 && currentRoom.Y != 0 && currentRoom.Visited != false)
			{
				if (hero.X == currentRoom.X && hero.Y == currentRoom.Y)
				{
					std::cout << "O";
				}
				else
				{
					std::cout << ".";
				}
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << "|" << std::endl;
	}
	std::cout << " ----------" << std::endl;
}

void GameController::MoveHero(int Direction)
{
	hero.Move(Direction);
}
