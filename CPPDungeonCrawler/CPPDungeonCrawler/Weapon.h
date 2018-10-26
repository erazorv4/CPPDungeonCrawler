#pragma once
#include "EquipableItem.h"
class Weapon :
	public EquipableItem
{
public:
	Weapon();
	~Weapon();

	int AttackChance;
	int Damage[2];
};

