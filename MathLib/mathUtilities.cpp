#include "mathUtilities.h"

int sum(int a, int b)
{
	return a + b;
}

int min(int a, int b)
{
	//Checks which value is less than the other
	return a < b ? a : b;
}

int max(int a, int b)
{
	//Checks which value is greater than the other
	return a > b ? a : b;
}

int clamp(int value, int min, int max)
{
	//If the value is greater than max, return max
	if (value > max)
	{
		return max;
	}
	//If the value is less than min, return min
	if (value < min)
	{
		return min;
	}
	//Otherwise, return the value
	return value;
}

int abs(int val)
{
	//If the value is negative, return the negative of it (this turns it positive)
	if (val < 0)
	{
		return (-val);
	}
	//Else, return val
	return val;
}

int pow(int base, int power)
{
	//Temp variable for original base
	int temp = base;
	//For each power
	for (int i = 0; i < power - 1; i++)
	{
		//set base equal to base times the original base
		base = base * temp;
	}
	return base;
}

bool isPowerOfTwo(int val)
{
	//Checks whether a number is zero or not
	if (val == 0)
	{
		return false;
	}

	//True while val is not equal to 1
	while (val != 1)
	{
		//checks whether val is divisible by 2
		if (val % 2 != 0)
		{
			//If val is not divisible by 2, return false
			return false;
		}
		//Divides val by 2
		val /= 2;
	}
	//Returns true if the number is divisible
	return true;
}

int nextPowerOfTwo(int val)
{
	//Checks if val is a power of two
	if (isPowerOfTwo(val))
	{
		//Returns val * 2 (The next power of two)
		return val * 2;
	}
}

float moveTowards(float current, float target, float maxDelta)
{
	//If the current value plus the maxDelta is less than the target
	if (current + maxDelta <= target)
	{
		//Add maxDelta to the current value
		return current += maxDelta;
	}
	//FOR GOING BACKWARDS: If the current value minus the maxDelta is greater than the target
	if (current - maxDelta >= target)
	{
		//Subtract maxDelta from the current value
		return current -= maxDelta;
	}
	//Else return target 
	return target;
}

bool assert(const char * testName, bool expression)
{
	if (expression)
	{
		std::cout << "Pass " << testName << std::endl;
	}

	std::cout << "Fail " << testName << std::endl;
	return false;
}

bool assert(const char * testName, int expected, int actual)
{
	if (expected == actual)
	{
		std::cout << "Pass " << testName << std::endl;
		return true;
	}
	std::cout << "Fail " << testName << std::endl;
	return false;
}

bool assert(const char * testName, float expected, float actual, float tolerance)
{
	if (expected >= actual - tolerance && expected <= actual + tolerance)
	{
		std::cout << "Pass " << testName << std::endl;
		return true;
	}
	std::cout << "Fail " << testName << std::endl;
	return false;
}

