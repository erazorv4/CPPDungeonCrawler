#pragma once
#include "EquipableItem.h"
class Shield :
	public EquipableItem
{
public:
	Shield(int blockChance);
	~Shield();

	int BlockChance;
};

