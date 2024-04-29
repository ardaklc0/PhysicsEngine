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
#define MAX_INPUT_CHARS_POSITION 3
#define MAX_INPUT_CHARS_VELOCITY 3
SecondOrderEulerMethod second_order_euler = SecondOrderEulerMethod(0, 0, 0, 0.001);

float freeFall(float t, float y, float y_prime) {
	// y'' = -g
	return -9.80665;
}

float initialYPosition = 25;
double startTime = GetTime(); // Get the start time
char elapsedTimeStr[10];
char lastTime[10];
char currentPosition[10];
char velocity[10];
double elapsedTime;
double currentTime;
int index;
vector<Vector2D> result;
vector<float> timeList;
float resultSize;
vector<pair<float, Vector2D>> resultList;
float timeDelta;
float initialMeter;
float initialVelocity = 0;


int main() {
	const int screenWidth = 600;
	const int screenHeight = 600;
	InitWindow(screenWidth, screenHeight, "Test");
	SetTargetFPS(70);
	
	char namePosition[MAX_INPUT_CHARS_POSITION + 1] = "\0";
	char nameVelocity[MAX_INPUT_CHARS_VELOCITY + 1] = "\0";
	
	int letterCountPosition = 0;
	int letterCountVelocity = 0;

	Rectangle textBoxPosition = { screenWidth - 85, 60, 50, 25};
	Rectangle submitButton = { screenWidth - 240, 200, 220, 25 };
	Rectangle textBoxVelocity = { screenWidth - 85, 100, 50, 25 };

	bool mouseOnTextPosition = false;
	bool mouseOnSubmitButton = false;
	bool mouseOnTextVelocity = false;

	int framesCounterPosition = 0;
	int framesCounterSubmitButton = 0;
	int framesCounterVelocity = 0;

	second_order_euler = SecondOrderEulerMethod(0, initialYPosition, 0, 0.001);
	resultList = second_order_euler.solve(10000, freeFall);
	resultSize = resultList.size();
	if (!resultList.empty()) {
		for (const auto& pair : resultList) {
			result.push_back(pair.second);
			timeList.push_back(pair.first);
		}
	}
	timeDelta = resultList.back().first;
	initialMeter = second_order_euler.y0 / 10;

	while (!WindowShouldClose())
	{
		DrawText("Initial Position: ", screenWidth - 240, 70, 18, RED);
		DrawText("Initial Velocity: ", screenWidth - 240, 100, 18, RED);
		snprintf(velocity, 10, "%.2f", initialVelocity);
		DrawText(velocity, screenWidth - 85, 60, 18, RED);

		if (CheckCollisionPointRec(GetMousePosition(), textBoxPosition)) mouseOnTextPosition = true;
		else mouseOnTextPosition = false;
		if (mouseOnTextPosition)
		{
			SetMouseCursor(MOUSE_CURSOR_IBEAM);
			int keyX = GetCharPressed();
			while (keyX > 0)
			{
				if ((keyX >= 32) && (keyX <= 125) && (letterCountPosition < MAX_INPUT_CHARS_POSITION))
				{
					namePosition[letterCountPosition] = (char)keyX;
					namePosition[letterCountPosition + 1] = '\0';
					letterCountPosition++;
				}
				keyX = GetCharPressed();
			}
			if (IsKeyPressed(KEY_BACKSPACE))
			{
				letterCountPosition--;
				if (letterCountPosition < 0) letterCountPosition = 0;
				namePosition[letterCountPosition] = '\0';
			}
		}

		else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
		if (mouseOnTextPosition) framesCounterPosition++;
		else framesCounterPosition = 0;

		if (CheckCollisionPointRec(GetMousePosition(), textBoxVelocity)) mouseOnTextVelocity = true;
		else mouseOnTextVelocity = false;
		if (mouseOnTextVelocity)
		{
			SetMouseCursor(MOUSE_CURSOR_IBEAM);
			int keyX = GetCharPressed();
			while (keyX > 0)
			{
				if ((keyX >= 32) && (keyX <= 125) && (letterCountVelocity < MAX_INPUT_CHARS_VELOCITY))
				{
					nameVelocity[letterCountVelocity] = (char)keyX;
					nameVelocity[letterCountVelocity + 1] = '\0';
					letterCountVelocity++;
				}
				keyX = GetCharPressed();
			}
			if (IsKeyPressed(KEY_BACKSPACE))
			{
				letterCountVelocity--;
				if (letterCountVelocity < 0) letterCountVelocity = 0;
				nameVelocity[letterCountVelocity] = '\0';
			}
		}

		else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
		if (mouseOnTextVelocity) framesCounterVelocity++;
		else framesCounterVelocity = 0;

		if (CheckCollisionPointRec(GetMousePosition(), submitButton)) mouseOnSubmitButton = true;
		else mouseOnSubmitButton = false;
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			// Reset time-related variables
			startTime = GetTime();
			elapsedTime = 0;

			// Assuming input position is in centimeters, convert to meters for simulation
			initialYPosition = std::stoi(namePosition);
			initialVelocity = std::stoi(nameVelocity);
			second_order_euler = SecondOrderEulerMethod(0, initialYPosition, initialVelocity, 0.001);
			resultList = second_order_euler.solve(10000, freeFall);
			resultSize = resultList.size();

			// Clear result and timeList vectors
			result.clear();
			timeList.clear();

			// Update initialMeter with the new position
			index = 0;
			if (!resultList.empty()) {
				for (const auto& pair : resultList) {
					result.push_back(pair.second);
					timeList.push_back(pair.first);
				}
			}
			timeDelta = resultList.back().first;
		}

		BeginDrawing();
		CustomRaylib::PlotDistanceRuler(screenWidth, screenHeight);
		ClearBackground(BLACK);

		currentTime = GetTime(); // Get the current time
		elapsedTime = currentTime - startTime; // Calculate elapsed time
		snprintf(elapsedTimeStr, 10, "%.2f", elapsedTime);

		if (elapsedTime < timeDelta) {
			index = static_cast<int>(elapsedTime * resultSize / timeDelta); // Calculate index based on elapsed time
			initialMeter = result[index].x / 10; // Update initialMeter based on the simulation result

			// Elapsed Time Visualization
			DrawCircle(screenWidth / 2, screenHeight - initialMeter * 60, 10, RED);
			DrawText("Elapsed Time: ", screenWidth - 240, 20, 18, RED);
			DrawText(elapsedTimeStr, screenWidth - 85, 20, 18, RED);
			DrawText("s", screenWidth - 30, 20, 18, RED);

			// Current Position Visualization
			snprintf(currentPosition, 10, "%.2f", initialMeter * 10);
			DrawText("Current Position: ", screenWidth - 240, 40, 18, RED);
			DrawText(currentPosition, screenWidth - 85, 40, 18, RED);
			DrawText("m", screenWidth - 30, 40, 18, RED);
	
		}
		
		if (elapsedTime >= timeDelta) {
			DrawCircle(screenWidth / 2, screenHeight - 10, 10, RED);

			// Elapsed Time Visualization
			snprintf(lastTime, 10, "%.2f", timeDelta);
			DrawText("Elapsed Time: ", screenWidth - 240, 20, 18, RED);
			DrawText(lastTime, screenWidth - 85, 20, 18, RED);
			DrawText("s", screenWidth - 30, 20, 18, RED);

			// Current Position Visualization
			snprintf(currentPosition, 10, "%.2f", initialMeter * 10);
			DrawText("Current Position: ", screenWidth - 240, 40, 18, RED);
			DrawText("0", screenWidth - 85, 40, 18, RED);
			DrawText("m", screenWidth - 30, 40, 18, RED);
		}		

		DrawRectangleRec(textBoxPosition, LIGHTGRAY);
		if (mouseOnTextPosition) DrawRectangleLines((int)textBoxPosition.x, (int)textBoxPosition.y, (int)textBoxPosition.width, (int)textBoxPosition.height, RED);
		else DrawRectangleLines((int)textBoxPosition.x, (int)textBoxPosition.y, (int)textBoxPosition.width, (int)textBoxPosition.height, DARKGRAY);
		DrawTextEx(GetFontDefault(), namePosition, { textBoxPosition.x + 5, textBoxPosition.y + 8 }, 20, 5, MAROON);

		DrawRectangleRec(submitButton, LIGHTGRAY);
		if (mouseOnSubmitButton) DrawRectangleLines((int)submitButton.x, (int)submitButton.y, (int)submitButton.width, (int)submitButton.height, RED);
		else DrawRectangleLines((int)submitButton.x, (int)submitButton.y, (int)submitButton.width, (int)submitButton.height, DARKGRAY);
		DrawTextEx(GetFontDefault(), "Submit", { submitButton.x + 12, submitButton.y + 8 }, 10, 5, MAROON);

		DrawRectangleRec(textBoxVelocity, LIGHTGRAY);
		if (mouseOnTextVelocity) DrawRectangleLines((int)textBoxVelocity.x, (int)textBoxVelocity.y, (int)textBoxVelocity.width, (int)textBoxVelocity.height, RED);
		else DrawRectangleLines((int)textBoxVelocity.x, (int)textBoxVelocity.y, (int)textBoxVelocity.width, (int)textBoxVelocity.height, DARKGRAY);
		DrawTextEx(GetFontDefault(), nameVelocity, { textBoxVelocity.x + 5, textBoxVelocity.y + 8 }, 20, 5, MAROON);

		EndDrawing();
	}
	CloseWindow();
	return 0;
}