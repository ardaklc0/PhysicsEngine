#include <iostream>
#include "euler_method.h"
#include "runge_kutta_4th.h"
#include "runge_kutta_fehlberg.h"
#include "second_order_euler_method.h"
#include "third_order_euler_method.h"
#include <cmath>
using namespace cyclone;
using namespace std;

float func(float t, float y, float y_prime) {
	return -9.68;
}

int main() {
	float initial_t = 0;
	float initial_y = 50;
	float initial_y_prime = 0;
	float step_size = 0.0001;
	float epochs = 99999;

	SecondOrderEulerMethod euler = SecondOrderEulerMethod(initial_t, initial_y, initial_y_prime, step_size);
	Vector2 resultEuler = euler.solveUntilZero(func);

	return 0;
}

/*	
	float initial_t = 0;
	float initial_y = 48;
	float initial_y_prime = 0;
	float step_size = 0.001;
	float epochs = 1999;
	
	SecondOrderEulerMethod second_order_euler = SecondOrderEulerMethod(initial_t, initial_y, initial_y_prime, step_size);
	cyclone::Vector2 resultSecondOrderEuler = second_order_euler.solve(epochs, func);

	float initial_t = 0;
	float initial_y = 48;
	float step_size = 0.001;
	float epochs = 1999;

	EulerMethod euler = EulerMethod(initial_t, initial_y, step_size);
	float resultEuler = euler.solve(epochs, func);
	cout << euler.t0 << endl;
	cout << euler.y0 << endl;
	cout << euler.h << endl;
	cout << resultEuler << endl;

	RungeKutta4 runge_kutta = RungeKutta4(initial_t, initial_y, step_size);
	float resultRK4 = runge_kutta.solve(epochs, func);
	cout << runge_kutta.t0 << endl;
	cout << runge_kutta.y0 << endl;
	cout << runge_kutta.h << endl;
	cout << resultRK4 << endl;

	RungeKuttaFehlberg runge_kutta_fehlberg = RungeKuttaFehlberg(initial_t, initial_y, step_size);
	float resultRKF = runge_kutta_fehlberg.solve(epochs, func);
	cout << runge_kutta_fehlberg.t0 << endl;
	cout << runge_kutta_fehlberg.y0 << endl;
	cout << runge_kutta_fehlberg.h << endl;
	cout << resultRKF << endl;
*/