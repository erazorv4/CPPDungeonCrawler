#include "stdafx.h"
#include "ArrayHelper.h"
#include "Directions.h"


ArrayHelper::ArrayHelper()
{
}


ArrayHelper::~ArrayHelper()
{
}

bool ArrayHelper::CheckArrayContainsElement(Directions::Direction direction, Directions::Direction directionarray[])
{
	for (int i = 0; i < sizeof(directionarray); i++)
	{
		if (direction == directionarray[i])
		{
			return true;
		}
	}
	return false;
}
