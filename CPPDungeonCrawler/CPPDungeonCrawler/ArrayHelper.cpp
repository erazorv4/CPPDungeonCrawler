#include "stdafx.h"
#include "ArrayHelper.h"


ArrayHelper::ArrayHelper()
{
}


ArrayHelper::~ArrayHelper()
{
}

bool ArrayHelper::CheckArrayContainsElement(int number, const int intarray[])
{
	for (int i = 0; i < sizeof(intarray); i++)
	{
		if (number == intarray[i])
		{
			return true;
		}
	}
	return false;
}
