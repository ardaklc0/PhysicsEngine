#include "vector2.h"
#include <vector>

class SecondOrderEulerMethod
{
public:
	float h;
	float t0;
	float y0;
	float y0_prime;

	SecondOrderEulerMethod(float t0, float y0, float y0_prime, float h = 1) :
		t0(t0), y0(y0), y0_prime(y0_prime), h(h) {}

	std::vector<Vector2D> solve(int n, float(*func)(float, float, float)) const;
	Vector2D solveUntilZero(float(*func)(float, float, float)) const;
};