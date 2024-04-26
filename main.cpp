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
	SecondOrderEulerMethod second_order_euler = SecondOrderEulerMethod(0, 50, 30, 0.01);
	vector<pair<float, Vector2D>> resultList = second_order_euler.solve(1000, freeFall);
	float resultSize = resultList.size();
	vector<Vector2D> result;
	vector<float> timeList;
	if (!resultList.empty()) {
		for (const auto& pair : resultList) {
			result.push_back(pair.second);
			timeList.push_back(pair.first);
		}
	}
	if (!resultList.empty()) {
		// Extract Vector2D objects from the pairs in the resultList
		for (const auto& pair : resultList) {
			result.push_back(pair.second);
		}
	}
	float time = resultList.back().first;
	float initialMeter = second_order_euler.y0 / 10;
	double startTime = GetTime(); // Get the start time


	while (!WindowShouldClose())
	{
		BeginDrawing();
		CustomRaylib::PlotDistanceRuler(screenWidth, screenHeight);
		ClearBackground(BLACK);
		double currentTime = GetTime(); // Get the current time
		double elapsedTime = currentTime - startTime; // Calculate elapsed time
		if (elapsedTime < time) {
			int index = static_cast<int>(elapsedTime * resultSize / time); // Calculate index based on elapsed time
			initialMeter = result[index].x / 10;
			DrawCircle(screenWidth / 2, screenHeight - initialMeter * 60, 10, RED);
		}
		EndDrawing();
		if (elapsedTime >= time) {
			DrawCircle(screenWidth / 2, screenHeight - 10, 10, RED);
		}		
	}



	CloseWindow();
	return 0;
}

