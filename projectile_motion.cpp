#include <iostream>
#include <cmath>
#include "euler_method.h"
#include "second_order_euler_method.h"
using namespace std;

float func1(float t, float y) {
	// y' = v_0 - g * t
	return 15 - 9.68 * t;
}

float func2(float t, float y, float y_prime) {
	// y'' = -g
	return -9.68;
}

int projectile() {
	EulerMethod euler = EulerMethod(0, 0, 0.01);
	euler.solve(1000, func1);

	cout << "----------------------------------------------------" << endl;

	SecondOrderEulerMethod second_order_euler = SecondOrderEulerMethod(0, 0, 10, 0.01);
	second_order_euler.solve(1000, func2);


	return 0;
}