#pragma once

#include <random>
#include <ctime>

class Random
{
public:
	Random();
	~Random();
	int Generate(int min, int max);
private:
	std::default_random_engine generator;
};

