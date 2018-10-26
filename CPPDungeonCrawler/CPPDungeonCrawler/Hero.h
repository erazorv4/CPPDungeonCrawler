#pragma once

#include "Room.h"

class Hero
{
public:
	Hero();
	~Hero();

	char Name[20];
	int Level;
	int Health;
	int MaxHealth;
	int Exp;
	int AttackChance;
	int DefendChance;

	int X;
	int Y;
	Room CurrentRoom;
};

