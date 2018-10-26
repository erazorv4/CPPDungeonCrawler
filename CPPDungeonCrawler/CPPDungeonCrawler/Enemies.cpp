#include "stdafx.h"
#include "Enemies.h"


Enemies::Enemies()
{
	Enemy *enemy0 = new Enemy(new char[20]{ "test" }, 1, 10, 10, new int[2]{ 1, 2 }, 10, 10);
	EnemyList[0] = enemy0;
}


Enemies::~Enemies()
{
	//TODO remove enemies i guess?
}
