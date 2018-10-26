#pragma once
class Enemy
{
public:
	Enemy();
	~Enemy();
	
	char Name[20];
	int Level;
	int Health;
	int MaxHealth;
	int Damage[2];
	int AttackChance;
	int DefendChance;
};

