#include "second_order_euler_method.h"
#include <iostream>
using namespace cyclone;
using namespace std;

cyclone::Vector2 SecondOrderEulerMethod::solve(int n, float(*func)(float, float, float)) const
{
	float t = t0;
	Vector2 y = Vector2(
		y0,
		y0_prime
	);
	for (int i = 0; i < n; i++)
	{
		y = Vector2(
			y[0] + h * y[1],
			y[1] + h * func(t, y[0], y[1])
		);
		t = t + h;
		if (i % 100 == 0)
			cout << "(t, y)" << " = " << "(" << t << ", " << "(" << y[0] << ", " << y[1] << ")" << ")" << endl;
	}
	return y;
}