#include "second_order_euler_method.h"
#include <iostream>
using namespace std;
#include <cmath>

Vector2D SecondOrderEulerMethod::solve(int n, float(*func)(float, float, float)) const
{
	float t = t0;
	Vector2D y = Vector2D(
		y0,
		y0_prime
	);
	for (int i = 0; i < n; i++)
	{
		y = Vector2D(
			y[0] + h * y[1],
			y[1] + h * func(t, y[0], y[1])
		);
		t = t + h;
		if (i % 10 == 0)
			cout << "(t, y, v)" << " = " << "(" << t << ", " << y[0] << ", " << y[1] << ")" << endl;
	}
	return y;
}

Vector2D SecondOrderEulerMethod::solveUntilZero(float(*func)(float, float, float)) const
{
	float t = t0;
	Vector2D y = Vector2D(
		y0,
		y0_prime
	);
	int i = 0;
	float speed = 0;
	while (y[0] >= 0.0)
	{
		i = i + 1;
		y = Vector2D(
			y[0] + h * y[1],
			y[1] + h * func(t, y[0], y[1])
		);
		t = t + h;
		speed = sqrt(y[1] * y[1]);
		if (i % 10 == 0)
			cout << "(t, y, v, speed)" << " = " << "(" << t << ", " << "(" << y[0] << ", " << y[1] << ", " << speed << ")" << ")" << endl;
	}
	return y;
}