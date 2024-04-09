#include <iostream>
#include "euler_method.h"
using namespace std;

float func(float t, float y) {
	return y;
}

int main() {
	float initial_t = 0;
	float initial_y = 1;
	float step_size = 0.01;
	float epochs = 512;
	EulerMethod euler = EulerMethod(initial_t, initial_y, step_size);
	float result = euler.solve(epochs, func);
	
	cout << euler.t0 << endl;
	cout << euler.y0 << endl;
	cout << euler.h << endl;
	cout << result << endl;

	return 0;
}