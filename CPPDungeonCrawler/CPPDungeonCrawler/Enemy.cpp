#include "stdafx.h"
#include "Enemy.h"
#include <array>

Enemy::Enemy()
{
}


Enemy::Enemy(char name[20], int level, int health, int maxhealth, int damage[2], int attackchance, int defendchance, int attacktimes)
	: Level(level), Health(health), MaxHealth(maxhealth), AttackChance(attackchance), DefendChance(defendchance), AttackTimes(attacktimes)
{
	std::copy(name, name + 20, Name);
	std::copy(damage, damage + 2, Damage);
}

Enemy::~Enemy()
{
}
