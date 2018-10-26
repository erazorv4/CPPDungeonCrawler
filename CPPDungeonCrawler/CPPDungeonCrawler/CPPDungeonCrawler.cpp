#include "stdafx.h"
#include <iostream>
#include <random>
#include <ctime>
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	std::default_random_engine generator;
	generator.seed(time(0));

	//voorbeeld 1
	std::uniform_int_distribution<int> distribution1(1, 6);
	cout << "Random getallen van 1 t/m 6: ";
	for (int i = 0; i < 10; ++i)
	{
		cout << distribution1(generator) << ", ";
	}
	cout << endl;

	//voorbeeld 2
	std::uniform_int_distribution<int> distribution2(20, 100);
	cout << "Random getallen van 20 t/m 100: ";
	for (int i = 0; i < 10; ++i)
	{
		cout << distribution2(generator) << ", ";
	}
	cout << endl;

	char end;
	cin >> end;

	//Zie ook:
	//http://www.cplusplus.com/reference/random/

	return 0;
}