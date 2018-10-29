#pragma once
#include "Directions.h"
static class ArrayHelper
{
public:
	ArrayHelper();
	~ArrayHelper();
	//This can be overloaded to support other types.
	static bool CheckArrayContainsElement(Directions::Direction direction, Directions::Direction directionarray[]);
};

