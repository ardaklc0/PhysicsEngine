#include <iostream>
#include <cmath>
#include "vector2_particle.h"
#include "second_order_euler_method.h"
#include "euler_method.h"
#include "newton_differentiation.h"
#include "vector2.h"
#include <raylib.h>
using namespace std;


float func(float t, float y, float y_prime) {
	// y'' = v' = -3.9
	return -3.9;
}

float funcAccel(float t, float y) {
	// y'  = v  = 2.8
	return 2.8;
}


int main() {
	const int screenWidth = 600;
	const int screenHeight = 600;
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
	Vector2D result = eulerMethod.solve(1001, func);
	float acceleration = result.y;

	float friction = 0.45 * acceleration;
	pushForce.setFriction(friction);

	EulerMethod eulerMethod2 = EulerMethod(0, 0, 0.001); // (t0, y0, h)
	float result2 = eulerMethod2.solve(1001, funcAccel);


	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawLine(0, screenHeight / 2, screenWidth, screenHeight / 2, WHITE);
		DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);

		for (int i = -300; i <= 360; i += 60)
		{
			int index = i / 60;
			char str[10];
			sprintf_s(str, "%d", index);
			DrawCircle(screenWidth / 2 + i, screenHeight / 2, 3, RED);
			DrawText(str, screenWidth / 2 + i + 5, screenHeight / 2, 10, WHITE);

			if (i == 0)
				continue;

			DrawCircle(screenWidth / 2, screenHeight / 2 + i, 3, RED);
			DrawText(str, screenWidth / 2, screenHeight / 2 + i + 5, 10, WHITE);
		}

		EndDrawing();
	}


	CloseWindow();
	return 0;
}