#include <iostream>
#include <cmath>
#include "vector2_particle.h"
#include "second_order_euler_method.h"
#include "euler_method.h"
#include "newton_differentiation.h"
#include "vector2.h"
#include <raylib.h>
#include "custom_raylib.h"
#include <string>
#include <vector>
using namespace std;

#ifndef GRAVITY
#define GRAVITY 9.81
#endif

float lengthOfPendulum = 1; // meters

float secondDifferential(float t, float y, float y_prime) {
	return -GRAVITY / lengthOfPendulum * y;
}

int main(){
	SecondOrderEulerMethod secondOrderEulerMethod(0, 0, 30, 0.01);
	vector<std::pair<float, Vector2D>> result = secondOrderEulerMethod.solve(1000, secondDifferential);



	return 0;
}