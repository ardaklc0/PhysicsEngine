#include "third_order_euler_method.h"
#include <iostream>
using namespace cyclone;
using namespace std;

cyclone::Vector3 ThirdOrderEulerMethod::solve(int n, float(*func)(float, float, float, float)) const
{
	float t = t0;
	Vector3 y = Vector3(
		y0,
		y0_prime,
		y0_double_prime
	);
	for (int i = 0; i < n; i++)
	{
		y = Vector3(
			y[0] + h * y[1],
			y[1] + h * y[2],
			y[2] + h * func(t, y[0], y[1], y[2])
		);
		t = t + h;
		if (i % 100 == 0)
			cout << "(t, y)" << " = " << "(" << t << ", " << "(" << y[0] << ", " << y[1] << ", " << y[2] << ")" << ")" << endl;
	}
	return y;
}