#pragma once
static class ArrayHelper
{
public:
	ArrayHelper();
	~ArrayHelper();
	//This can be overloaded to support other types.
	static bool CheckArrayContainsElement(int number, const int intarray[]);
};

