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





int main() {
	float L1 = 1.5; // Length of the first pendulum
	float L2 = 1; // Length of the second pendulum

	float m1 = 1; // Mass of the first pendulum
	float m2 = 1; // Mass of the second pendulum

	float g = 9.81; // Acceleration due to gravity

    float t = 0; // Time
	float dt = 0.01; // Time step

	float theta1 = 80.5 * PI / 180; // Initial angle of the first pendulum
	float theta2 = 0 * PI / 180; // Initial angle of the second pendulum

	float theta1_dot = 0; // Initial angular velocity of the first pendulum
	float theta2_dot = 0; // Initial angular velocity of the second pendulum

	while (!WindowShouldClose())
	{
		BeginDrawing();

		EndDrawing();
	}
	CloseWindow();
	return 0;
}