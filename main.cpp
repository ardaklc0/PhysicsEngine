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


int counter;
vector<Vector2D> resultProjectile;
vector<float> resultXProjectile;
vector<float> resultYProjectile;
vector<float> timeListProjectile;
vector<pair<float, Vector2D>> resultListProjectile;
vector<char*> angleListProjectile;

int main() {
	const int screenWidth = 1000;
	const int screenHeight = 800;
	InitWindow(screenWidth, screenHeight, "Test");
	SetTargetFPS(60);
	
	float xAngle = cos(initialAngle * DEG2RAD) * initialVelocityProjectile;
	float yAngle = sin(initialAngle * DEG2RAD) * initialVelocityProjectile;

	for (float i = 0; i < 1000; i += 0.1) {
		float t = i * 0.1;
		float x = projectileX(t, initialYPositionProjectile, yAngle);
		float y = projectileY(t, initialXPositionProjectile, xAngle);
		float vx = projectileXVelocity(t, yAngle);
		float vy = projectileYVelocity(t, xAngle);
		currentAngleProjectileFloat = atan2(vx, vy) * RAD2DEG;
		snprintf(currentAngleProjectile, 10, "%.2f", currentAngleProjectileFloat);
		float v = sqrt(vx * vx + vy * vy);
		cout << "t: " << t << " " << "x: " << x << " y: " << y << " " << "vx: " << vx << " vy: " << vy << " v: " << v << " angle: " << currentAngleProjectile << endl;
		resultXProjectile.push_back(x);
		resultYProjectile.push_back(y);
		timeListProjectile.push_back(t);
		angleListProjectile.push_back(currentAngleProjectile);
		resultListProjectile.push_back(make_pair(t, Vector2D(x, y)));
		if (y < 0) {
			break;
		}
	}

	timeDeltaProjectile = resultListProjectile.back().first;
	initialMeterYProjectile = initialYPositionProjectile/10;
	initialMeterXProjectile = initialXPositionProjectile/10;
	float resultSize = resultListProjectile.size();


	while (!WindowShouldClose())
	{
		BeginDrawing();
		CustomRaylib::PlotDistanceRulerProjectile(screenWidth, screenHeight);
		ClearBackground(BLACK);

		currentTimeProjectile = GetTime();
		elapsedTimeProjectile = currentTimeProjectile - startTimeProjectile;
		snprintf(elapsedTimeStrProjectile, 10, "%.2f", elapsedTimeProjectile);

		
		if (elapsedTimeProjectile < timeDeltaProjectile) {
			counter = static_cast<int>(elapsedTimeProjectile * resultSize / timeDeltaProjectile); // Calculate index based on elapsed time
			initialMeterYProjectile = resultYProjectile[counter] / 10; // Update initialMeter based on the simulation result
			initialMeterXProjectile = resultXProjectile[counter] / 10;

			// Elapsed Time Visualization
			DrawCircle(60 + initialMeterXProjectile * 60, screenHeight - initialMeterYProjectile * 60, 10, RED);
			DrawText("Elapsed Time: ", screenWidth - 240, 20, 18, RED);
			DrawText(elapsedTimeStrProjectile, screenWidth - 85, 20, 18, RED);
			DrawText("s", screenWidth - 30, 20, 18, RED);

			// Current Position Visualization
			snprintf(currentPositionProjectile, 10, "%.2f", initialMeterYProjectile * 10);
			DrawText("Current Position: ", screenWidth - 240, 40, 18, RED);
			DrawText(currentPositionProjectile, screenWidth - 85, 40, 18, RED);
			DrawText("m", screenWidth - 30, 40, 18, RED);

			// Angle Visualization
			DrawText("Angle: ", screenWidth - 240, 60, 18, RED);
			DrawText(angleListProjectile[counter], screenWidth - 85, 60, 18, RED);
			DrawText("deg", screenWidth - 30, 60, 18, RED);

		}

		if (elapsedTimeProjectile >= timeDeltaProjectile) {
			DrawCircle(60, screenHeight - 10, 10, RED);

			// Elapsed Time Visualization
			snprintf(lastTimeProjectile, 10, "%.2f", timeDeltaProjectile);
			DrawText("Elapsed Time: ", screenWidth - 240, 20, 18, RED);
			DrawText(lastTimeProjectile, screenWidth - 85, 20, 18, RED);
			DrawText("s", screenWidth - 30, 20, 18, RED);

			// Current Position Visualization
			snprintf(currentPositionProjectile, 10, "%.2f", initialMeterYProjectile * 10);
			DrawText("Current Position: ", screenWidth - 240, 40, 18, RED);
			DrawText("0", screenWidth - 85, 40, 18, RED);
			DrawText("m", screenWidth - 30, 40, 18, RED);
		}




		EndDrawing();
	}
	CloseWindow();
	return 0;
}