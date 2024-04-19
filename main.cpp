#include <iostream>
#include <cmath>
#include "second_order_euler_method.h"
using namespace cyclone;
using namespace std;
#include <fstream>

float func(float t, float y, float y_prime) {
	return t;
}

int main() {

	SecondOrderEulerMethod soem(0.0, 0.0, 1.0, 0.001);
	soem.solveUntilZero(func);



	return 0;
}