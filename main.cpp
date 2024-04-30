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

float projectileX(float t, float x0, float vx) {
	return x0 + vx * t;
}

float projectileXVelocity(float t, float vx) {
	return vx;
}

float projectileY(float t, float y0, float vy) {
	return y0 + vy * t + 0.5 * -9.80665 * t * t;
}

float projectileYVelocity(float t, float vy) {
	return vy + -9.80665 * t;
}

float initialYPositionProjectile = 00;
float initialXPositionProjectile = 0;
float initialAngle = 45;
float initialVelocityProjectile = 30;

int counter;
vector<Vector2D> resultProjectile;
vector<float> timeListProjectile;
vector<pair<float, Vector2D>> resultListProjectile;


int main() {
	const int screenWidth = 600;
	const int screenHeight = 600;
	InitWindow(screenWidth, screenHeight, "Test");
	SetTargetFPS(70);
	
	float xAngle = cos(initialAngle * DEG2RAD) * initialVelocityProjectile;
	float yAngle = sin(initialAngle * DEG2RAD) * initialVelocityProjectile;


	for (float i = 0; i < 1000; i += 0.1) {
		float t = i * 0.1;
		float x = projectileX(t, initialYPositionProjectile, yAngle);
		float y = projectileY(t, initialXPositionProjectile, xAngle);
		float vx = projectileXVelocity(t, yAngle);
		float vy = projectileYVelocity(t, xAngle);
		float v = sqrt(vx * vx + vy * vy);
		cout << "t: " << t << " " << "x: " << x << " y: " << y << " " << "vx: " << vx << " vy: " << vy << " v: " << v << endl;
		if (y < 0) {
			break;
		}
		
	}
	


	while (!WindowShouldClose())
	{
		BeginDrawing();
		CustomRaylib::PlotDistanceRuler(screenWidth, screenHeight);
		ClearBackground(BLACK);


		EndDrawing();
	}
	CloseWindow();
	return 0;
}