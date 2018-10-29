#pragma once

#include "Enemy.h"

class Enemies
{
public:
	Enemies();
	~Enemies();

	Enemy* EnemyList[12];
	Enemy* BossList[2];
};

