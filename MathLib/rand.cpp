#include "rand.h"

int seedr = 666666;

void seedRand(int seedValue)
{
	seedr = seedValue;
}

int getRandSeed()
{
	int temp = seedr * seedr;
	std::string tempS = std::to_string(temp);
	int middle = tempS.length() / 2 - 1;
	std::string seedString;
	seedString += tempS[middle - 2];
	seedString += tempS[middle - 1];
	seedString += tempS[middle];
	seedString += tempS[middle + 1];
	seedString += tempS[middle + 2];
	seedString += tempS[middle + 3];
	return seedr = atoi(seedString.c_str());
}

