#pragma once
#include "EquipableItem.h"
class Armor :
	public EquipableItem
{
public:
	Armor();
	~Armor();

	int BlockChance;
	int DamageReduction;
};

