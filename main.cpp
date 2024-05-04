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





double startTimeProjectile = GetTime();
float initialYPositionProjectile = 0;
float initialXPositionProjectile = 0;
float initialAngle = 30;
float initialVelocityProjectile = 20;
double elapsedTimeProjectile;
double currentTimeProjectile;
float timeDeltaProjectile;
float initialMeterYProjectile;
float initialMeterXProjectile;
char currentPositionProjectile[10];
char elapsedTimeStrProjectile[10];
char lastTimeProjectile[10];
char currentAngleProjectile[10];
float currentAngleProjectileFloat;

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