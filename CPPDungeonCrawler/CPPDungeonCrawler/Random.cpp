#include "stdafx.h"
#include "Random.h"


Random::Random()
{
	generator.seed(time(0));
}


Random::~Random()
{
}

int Random::Generate(int min, int max)
{
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(generator);
}