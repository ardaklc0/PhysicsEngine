#include <iostream>
#include "matrix2.h"
#include "matrix3.h"
#include <cmath>
using namespace cyclone;
using namespace std;



int main() {
	Matrix2 matrix = {2, 4,
					  5, 1};
	float determinant = matrix.determinant();
	cout << "Determinant: " << determinant << endl;
	matrix.setInverse();
	cout << "Inverse: " << matrix.data[0] << " " << matrix.data[1] << "\n"
						<< matrix.data[2] << " " << matrix.data[3] << endl;
	
	Matrix3 matrix3 = {1, 2, 3,
					   4, 5, 6,
					   7, 8, 9};

	float determinant3 = matrix3.determinant();
	cout << "Determinant: " << determinant3 << endl;
	matrix3.setInverse();
	cout << "Inverse: " << matrix3.data[0] << " " << matrix3.data[1] << " " << matrix3.data[2] << "\n"
						<< matrix3.data[3] << " " << matrix3.data[4] << " " << matrix3.data[5] << "\n"
						<< matrix3.data[6] << " " << matrix3.data[7] << " " << matrix3.data[8] << endl;
	return 0;
}


/*	
	float func(float t, float y, float y_prime) {
		return -9.68;
	}

	float initial_t = 0;
	float initial_y = 50;
	float initial_y_prime = 0;
	float step_size = 0.0001;
	float epochs = 99999;

	SecondOrderEulerMethod euler = SecondOrderEulerMethod(initial_t, initial_y, initial_y_prime, step_size);
	Vector2 resultEuler = euler.solveUntilZero(func);

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