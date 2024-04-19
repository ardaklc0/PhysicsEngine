#include <iostream>
#include <cmath>
#include "euler_method.h"
using namespace std;

float func(float t, float y) {
	// y' = v_0 - g * t
	return 10 - 9.68 * t;
}

int main() {
	EulerMethod euler = EulerMethod(0, 0, 0.01);
	float result = euler.solve(1000, func);

	return 0;
}