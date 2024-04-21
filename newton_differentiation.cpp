#include "newton_differentiation.h"
#include <iostream>
using namespace std;

float NewtonDifferentiation::solve(int n, float(*func)(float)) const
{
	float x0 = x;
	float derivative = 0;
	float h0 = h;
	for (int i = 0; i < n; i++)
	{
		derivative = (func(x0 + h) - func(x0 - h)) / (2 * h);
		if (i % 10 == 0)
			cout << func(x0 + h) << " - " << func(x0 - h) << " / " << 2 * h << endl;
			cout << "(x, y)" << " = " << "(" << x0 << ", " << derivative << ")" << endl;
		x0 = x0 + h0;
	}
	return derivative;
}
