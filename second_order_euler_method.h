#include "vector2.h"

class SecondOrderEulerMethod
{
public:
	float h;
	float t0;
	float y0;
	float y0_prime;

	SecondOrderEulerMethod(float t0, float y0, float y0_prime, float h = 1) :
		t0(t0), y0(y0), y0_prime(y0_prime), h(h) {}

	cyclone::Vector2 solve(int n, float(*func)(float, float, float)) const;
	cyclone::Vector2 solveUntilZero(float(*func)(float, float, float)) const;
};