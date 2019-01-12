#pragma once
#include <iostream>
#include <string>
//PI
const double PI = 3.14159265358979323846;
// Degree to Radians
const double DEG_TO_RAD = PI / 180;
// Radians to Degrees
const double RAD_TO_DEG = 180 / PI;
int sum(int a, int b);
//Return the smaller of two values
int min(int a, int b);
//Return the larger of two values
int max(int a, int b);
//Return value if it is between min and max
int clamp(int value, int min, int max);
//Returns the absolute value of a value
int abs(int val);
//Returns the value of base to the power of power
int pow(int base, int power);
//Returns true if the value is a power of two
bool isPowerOfTwo(int val);
//Returns the next power of two. If the number is not a power of two, it returns 0
int nextPowerOfTwo(int val);
//Moves the current value towards the target value by maxDelta
float moveTowards(float current, float target, float maxDelta);

bool assert(const char * testName, bool expression);
bool assert(const char * testName, int expected, int actual);
bool assert(const char * testName, float expected, float actual, float tolerance);

template <typename T> 
inline T lerp(const T& a, const T& b, float t)
{
	return a * (1 - t) + b * t;
}

namespace Tweening 
{ 
	template <typename T> 
	inline T linearEase(float t, const T& b, const T& c, float d) 
	{ 
		return b + c * (t / d); 
	}  
	
	template <typename T>
	inline T easeInSine(float t, const T& b, const T& c, float d)
	{
		return b + c - c * cosf(t / d * (PI / 2));
	}
}

template <typename T> 
T quadraticBezier(const T& a, const T& b, const T& c, float t) 
{ 
	T x = lerp(a, b, t); 
	T y = lerp(b, c, t); 
	return lerp(x, y, t); 
}

template <typename T> 
T cubicBezier(const T& a, const T& b, const T& c, const T& d, float t) 
{ 
	T x = lerp(a, b, t); 
	T y = lerp(b, c, t); 
	T z = lerp(c, d, t); 
	return quadraticBezier(x, y, z, t); 
}