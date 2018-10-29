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
		input = cin.get();
		
		if (input == 't')
		{
			cout << "testts";
		}
		else if (input == 'q')
		{
			controller.GameIsRunning = false;
		}
	}


	char end;
	cin >> end;

	return 0;
}