#include <iostream>
#include "euler_method.h"
#include "runge_kutta_4th.h"
#include "runge_kutta_fehlberg.h"
using namespace std;

float func(float t, float y) {
	return y;
}

int main() {
	float initial_t = 0;
	float initial_y = 1;
	float step_size = 0.01;
	float epochs = 2048;

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

	return 0;
}