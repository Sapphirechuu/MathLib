#pragma once
#include <iostream>
#include <string>

extern int seedr; 

int getRandSeed();
void seedRand(int seedValue);

template <typename T>
T rand(T min, T max)
{
	int result = NULL;
	result = seedr % max;
	result += min;
	getRandSeed();
	std::cout << result << std::endl;
	return result;
};

template <typename T>
T randDecimal(T min, T max)
{
	T result = NULL;
	result = (seedr / max);
	while (result > max)
	{
		result = (result / max);
	}
	result += min;
	getRandSeed();
	std::cout << result << std::endl;
	return result;
};

