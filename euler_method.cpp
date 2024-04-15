#include "euler_method.h"
#include <iostream>
using namespace std;

float EulerMethod::solve(int n, float(*func)(float, float)) const
{
	float t = t0;
	float y = y0;
	for (int i = 0; i < n; i++)
	{
		y = y + h * func(t, y);	
		t = t + h;
		if (i % 100 == 0)
			cout << "(t, y)" << " = " << "(" << t << ", " << y << ")" << endl;
		if (y < 0)
			break;
	}
	return y;
}