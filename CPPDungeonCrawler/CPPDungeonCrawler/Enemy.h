#pragma once

class Enemy
{
public:
	Enemy();
	Enemy(char name[20], int level, int health, int maxhealth, int damage[2], int attackchance, int defendchance);
	~Enemy();
	
	char Name[20];
	int Level;
	int Health;
	int MaxHealth;
	int Damage[2];
	int AttackChance;
	int DefendChance;
};

