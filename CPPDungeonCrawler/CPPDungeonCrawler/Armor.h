#pragma once
#include "EquipableItem.h"
class Armor :
	public EquipableItem
{
public:
	Armor(int damageReduction);
	~Armor();

	int DamageReduction;
};

