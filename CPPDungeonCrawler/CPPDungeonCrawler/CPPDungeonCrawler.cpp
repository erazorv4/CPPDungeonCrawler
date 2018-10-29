#include "stdafx.h"
#include <iostream>
#include <random>
#include <ctime>
#include <string>

#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h> 

#include "GameController.h"

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);

	cout << "Beginning of game." << endl;

	GameController controller = GameController();

	char end;
	cin >> end;

	return 0;
}