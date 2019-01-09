#include <iostream>
#include "mathUtilities.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "rand.h"

int main()
{
	int a = 2;
	int b = 5;

	int testmin = min(a, b);
	int testmax = max(a, b);
	int testClamp = clamp(3, a, b);

	double testToRAD = 60 * DEG_TO_RAD;
	double testToDeg = testToRAD * RAD_TO_DEG;

	int testAbs = abs(-9);
	int testPow = pow(27, .5);
	bool testPowOfTwo = isPowerOfTwo(8);
	int testNextPowOfTwo = nextPowerOfTwo(1024);
	float testMoveTowards = moveTowards(1, 4, .5);

	assert("test", (!true));
	assert("sum I", 3, sum(1, 2));
	assert("sum II", 5, sum(2, 3));
	assert("min", 3, min(3, 7));
	assert("max", 7, max(3, 7));
	assert("clamp", 5, clamp(5, 3, 7));

	vec3 x = { 2, 2, 2 };
	vec3 y = { 1, 1, 1 };
	vec3 diff = x - y;

	assert("diff x", 1.0f, diff.x, 0.0001f);
	assert("diff y", 1.0f, diff.y, 0.0001f);
	assert("diff z", 1.0f, diff.z, 0.0001f);

	seedRand(666666);
	randDecimal(1.2f, 20.0f);
	randDecimal(1.2f, 20.0f);
	randDecimal(1.2f, 20.0f);
	randDecimal(1.2f, 20.0f);
	randDecimal(1.2f, 20.0f);
	randDecimal(1.2f, 20.0f);
	randDecimal(1.2f, 20.0f);
	randDecimal(1.2f, 20.0f);
	randDecimal(1.2f, 20.0f);
	randDecimal(1.2f, 20.0f);
	randDecimal(1.2f, 20.0f);
	randDecimal(1.2f, 20.0f);
	randDecimal(1.2f, 20.0f);
	randDecimal(1.2f, 20.0f);
	randDecimal(1.2f, 20.0f);
	randDecimal(1.2f, 20.0f);
	return 0;
}