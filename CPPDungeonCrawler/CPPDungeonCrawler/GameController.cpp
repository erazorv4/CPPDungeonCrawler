#include "stdafx.h"
#include "GameController.h"
#include <iostream>


GameController::GameController()
{
	currentMap = Map(10, 10);

	DisplayMap();

	hero.X = currentMap.startRoom.X;
	hero.Y = currentMap.startRoom.Y;
}


GameController::~GameController()
{

}

void GameController::DisplayMap()
{
	//TODO improve this.
	std::cout << std::endl;
	std::cout << " ----------" << std::endl;
	for (int y = 1; y <= Height; y++)
	{
		std::cout << "|";
		for (int x = 1; x <= Width; x++)
		{
			Room currentRoom = currentMap.CheckRoomExists(x, y);
			if (currentRoom.X != 0 && currentRoom.Y != 0)
			{
				std::cout << ".";
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