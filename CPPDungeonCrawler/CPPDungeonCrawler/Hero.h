#pragma once
#include <string>

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

};

