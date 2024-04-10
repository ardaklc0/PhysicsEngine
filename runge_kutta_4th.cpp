#include "runge_kutta_4th.h"
#include <iostream>
using namespace std;

float RungeKutta4::solve(int n, float(*func)(float, float)) const
{
	float t = t0;
	float y = y0;
	for (int i = 0; i < n; i++)
	{
		float z1 = h * func(t, y);
		float z2 = h * func(t + h / 2, y + z1 / 2);
		float z3 = h * func(t + h / 2, y + z2 / 2);
		float z4 = h * func(t + h, y + z3);
		y = y + (z1 + 2 * z2 + 2 * z3 + z4) / 6;
		t = t + h;
		cout << "(t, y)" << " = " << "(" << t << ", " << y << ")" << endl;
	}
	return y;
}