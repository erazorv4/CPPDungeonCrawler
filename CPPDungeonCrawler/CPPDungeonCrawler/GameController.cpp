#include "stdafx.h"
#include "GameController.h"
#include <iostream>


GameController::GameController()
{
	currentMap = Map(10, 10);
	hero.X = currentMap.startRoom.X;
	hero.Y = currentMap.startRoom.Y;

	DisplayMap();

}


GameController::~GameController()
{

}

void GameController::DisplayMap()
{
	//TODO improve this.
	std::cout << std::endl;
	std::cout << " ----------" << std::endl;
	for (int y = 1; y <= currentMap.Height; y++)
	{
		std::cout << "|";
		for (int x = 1; x <= currentMap.Width; x++)
		{
			Room currentRoom = currentMap.CheckRoomExists(x, y);
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
}
