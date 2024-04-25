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

float freeFall(float t, float y, float y_prime) {
	// y'' = -g
	return -9.68;
}

int main() {
	const int screenWidth = 600;
	const int screenHeight = 600;
	InitWindow(screenWidth, screenHeight, "Test");
	SetTargetFPS(70);
	SecondOrderEulerMethod second_order_euler = SecondOrderEulerMethod(0, 50, 0, 0.01);
	vector<Vector2D> resultList = second_order_euler.solve(1000, freeFall);
	float resultSize = resultList.size();
	cout << "Result size: " << resultSize << endl;
	float initialMeter = second_order_euler.y0 / 10;
	double startTime = GetTime(); // Get the start time
	while (!WindowShouldClose())
	{
		BeginDrawing();
		CustomRaylib::PlotDistanceRuler(screenWidth, screenHeight);
		ClearBackground(BLACK);
		double currentTime = GetTime(); // Get the current time
		double elapsedTime = currentTime - startTime; // Calculate elapsed time
		if (elapsedTime < 3.21095) { // Check if animation time is less than 3.2 seconds
			int index = static_cast<int>(elapsedTime * resultSize / 3.21095); // Calculate index based on elapsed time
			initialMeter = resultList[index].x / 10;
			DrawCircle(screenWidth / 2, screenHeight - initialMeter * 60, 10, WHITE);
		}
		EndDrawing();
		if (elapsedTime >= 3.21095) // End the animation after 3.2 seconds
			break;
	}

	CloseWindow();
	return 0;
}

