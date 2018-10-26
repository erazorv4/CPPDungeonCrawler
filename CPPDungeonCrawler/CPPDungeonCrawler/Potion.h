#pragma once
#include "UsableItem.h"
class Potion :
	public UsableItem
{
public:
	Potion();
	~Potion();
	void Use();
};

