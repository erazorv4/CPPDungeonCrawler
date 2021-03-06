#include "stdafx.h"
#include <iostream>
#include <random>
#include <ctime>
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "GameController.h"
#include "CPPDungeonCrawler.h"

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	cout << "Beginning of game." << endl;

	GameController controller = GameController();


	while (controller.GameIsRunning)
	{
		char input;
		cin >> input;
		system("cls");
		
		if (input == 'w')
		{
			controller.MoveHero(0);
		}
		else if (input == 'a')
		{
			controller.MoveHero(3);
		}
		else if (input == 's')
		{
			controller.MoveHero(2);
		}
		else if (input == 'd')
		{
			controller.MoveHero(1);
		}
		else if (input == 't')
		{
			cout << "testts";
		}
		else if (input == 'q')
		{
			controller.GameIsRunning = false;
		}
		controller.DisplayMap();
	}
	
	return 0;
}