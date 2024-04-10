#include "vector3.h"

class ThirdOrderEulerMethod
{
public:
	float h;
	float t0;
	float y0;
	float y0_prime;
	float y0_double_prime;
	ThirdOrderEulerMethod(float t0, float y0, float y0_prime, float y0_double_prime, float h = 1) :
		t0(t0), y0(y0), y0_prime(y0_prime), y0_double_prime(y0_double_prime), h(h) {}

	cyclone::Vector3 solve(int n, float(*func)(float, float, float, float)) const;
};