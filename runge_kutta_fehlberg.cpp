#include "runge_kutta_fehlberg.h"
#include <iostream>
using namespace std;

float RungeKuttaFehlberg::solve(int n, float(*func)(float, float)) const
{
	float t = t0;
	float y = y0;
	for (int i = 0; i < n; i++)
	{
		float z1 = h * func(t, y);
		float z2 = h * func(t + h / 4, y + z1 / 4);
		float z3 = h * func(t + 3 * h / 8, y + 3 * z1 / 32 + 9 * z2 / 32);
		float z4 = h * func(t + 12 * h / 13, y + 1932 * z1 / 2197 - 7200 * z2 / 2197 + 7296 * z3 / 2197);
		float z5 = h * func(t + h, y + 439 * z1 / 216 - 8 * z2 + 3680 * z3 / 513 - 845 * z4 / 4104);
		float z6 = h * func(t + h / 2, y - 8 * z1 / 27 + 2 * z2 - 3544 * z3 / 2565 + 1859 * z4 / 4104 - 11 * z5 / 40);
		y = y + 25 * z1 / 216 + 1408 * z3 / 2565 + 2197 * z4 / 4104 - z5 / 5;
		t = t + h;

		if (i % 100 == 0)
			cout << "(t, y)" << " = " << "(" << t << ", " << y << ")" << endl;
	}
	return y;
}