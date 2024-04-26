#include <iostream>
#include <cmath>
#include "vector2_particle.h"
#include "second_order_euler_method.h"
#include "euler_method.h"
#include "newton_differentiation.h"
#include "vector2.h"
#include <raylib.h>
#include "custom_raylib.h"
#include <vector>
using namespace std;

#ifndef MilkBottle
#define MilkBottle

float func(float t, float y, float y_prime) {
	// y'' = v' = -3.9
	return -3.9;
}

float funcAccel(float t, float y) {
	// y'  = v  = 2.8
	return 2.8;
}


int milkBottleFMa() {
	const int screenWidth = 650;
	const int screenHeight = 650;
	InitWindow(screenWidth, screenHeight, "Test");
	SetTargetFPS(60);

	Vector2Particle pushForce = Vector2Particle(Vector2D(1, 0), 0, 0.45, 2.8, 0); // N, kg, m/s, Ns/m
	float initialVelocity = pushForce.getVelocity(); // m/s
	float mass = pushForce.getMass(); // kg
	Vector2D initialPosition = pushForce.getPosition(); // meters
	float lastVelocity = 0; // m/s
	float xDistance = 1; // meters

	cout << "(x, y) = " << "(" << initialPosition.x << ", " << initialPosition.y << ")" << endl; // (1, 0)
	cout << "v0x: " << initialVelocity << endl; // 2.8
	cout << "m: " << mass << endl; // 0.45

	SecondOrderEulerMethod eulerMethod = SecondOrderEulerMethod(0, 0, 2.8, 0.001); // (t0, y0, y0_prime, h)
	//vector<Vector2D> result = eulerMethod.solve(1001, func);
	//float acceleration = result.y;

	//float friction = 0.45 * acceleration;
	//pushForce.setFriction(friction);

	EulerMethod eulerMethod2 = EulerMethod(0, 0, 0.001); // (t0, y0, h)
	float result2 = eulerMethod2.solve(1001, funcAccel);


	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		CustomRaylib::PlotAxis(screenWidth, screenHeight);

		DrawCircle(screenWidth / 2 + initialPosition.x * 60, screenHeight / 2 - initialPosition.y * 60, 3, RED);
		DrawLine(screenWidth / 2, screenHeight / 2, screenWidth / 2 + initialPosition.x * 60, screenHeight / 2 - initialPosition.y * 60, RED);

		EndDrawing();
	}


	CloseWindow();
	return 0;
}
#endif // !




