#include "stdafx.h"
#include "Hero.h"
#include <array>

Hero::Hero()
{
}

Hero::Hero(char name[20], int level, int health, int maxhealth, int exp, int attackchance, int defendchance)
	: Level(level), Health(health), MaxHealth(maxhealth), Exp(exp), AttackChance(attackchance), DefendChance(defendchance)
{
	std::copy(name, name + 20, Name);
}


Hero::~Hero()
{
}
