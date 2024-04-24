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
using namespace std;

#define MAX_INPUT_CHARS_X 1
#define MAX_INPUT_CHARS_Y 1
int main() {
	const int screenWidth = 650;
	const int screenHeight = 650;
	InitWindow(screenWidth, screenHeight, "Test");
	char nameX[MAX_INPUT_CHARS_X + 1] = "\0";      // NOTE: One extra space required for null terminator char '\0'
	char nameY[MAX_INPUT_CHARS_Y + 1] = "\0";      // NOTE: One extra space required for null terminator char '\0'
	int letterCountX = 0;
	int letterCountY = 0;
	Rectangle textBoxX = { 545, 10, 25, 25 };
	Rectangle textBoxY = { 585, 10, 25, 25 };
	Rectangle submitButton = { 500, 40, 75, 25 };
	bool mouseOnSubmitButton = false;
	bool mouseOnTextX = false;
	bool mouseOnTextY = false;
	int framesCounterX = 0;
	int framesCounterY = 0;
	int framesCounterSubmitButton = 0;
	bool drawVector4 = false;
	SetTargetFPS(60);


	Vector2Particle particle1 = Vector2Particle(Vector2D(-3, 4), 250);
	Vector2Particle particle2 = Vector2Particle(Vector2D(1, 0), 50);
	Vector2Particle particle3 = Vector2Particle(Vector2D(0, -2), 120);
	float angle1 = particle1.getAngle();
	float angle2 = particle2.getAngle();
	float angle3 = particle3.getAngle();
	float Rx = particle1.getXForce() + particle2.getXForce() + particle3.getXForce();
	float Ry = particle1.getYForce() + particle2.getYForce() + particle3.getYForce();
	Vector2D R = particle1.getPosition() + particle2.getPosition() + particle3.getPosition();
	Vector2D ForceR = Vector2D(Rx, Ry);
	float RMagnitude = ForceR.magnitude();
	float angle4 = ForceR.angleBetweenVectorsInDegrees();
	cout << "Angle = " << angle1 << endl;
	cout << "(Fx1, Fy1) = " << "(" << particle1.getXForce() << ", " << particle1.getYForce() << ")" << endl;
	cout << "Angle = " << angle2 << endl;
	cout << "(Fx2, Fy2) = " << "(" << particle2.getXForce() << ", " << particle2.getYForce() << ")" << endl;
	cout << "Angle = " << angle3 << endl;
	cout << "(Fx3, Fy3) = " << "(" << particle3.getXForce() << ", " << particle3.getYForce() << ")" << endl;
	cout << "(Rx, Ry) = " << "(" << R.x << ", " << R.y << ")" << endl;
	cout << "|R| = " << RMagnitude << endl;
	cout << "Angle: " << angle4 << endl;
	float normalizedForce1 = (particle1.getNewton() - 50) / 250 + 1;
	cout << "Normalized Force 1: " << normalizedForce1 << endl;
	float normalizedForce2 = (particle2.getNewton() - 50) / 250 + 1;
	cout << "Normalized Force 2: " << normalizedForce2 << endl;
	float normalizedForce3 = (particle3.getNewton() - 50) / 250 + 1;
	cout << "Normalized Force 3: " << normalizedForce3 << endl;
	float normalizedForceR = (RMagnitude - 50) / 250 + 1;
	cout << "Normalized Force R: " << normalizedForceR << endl;

	while (!WindowShouldClose())
	{
		DrawTextEx(GetFontDefault(), "(x,y)=", { 467, 14 }, 20, 5, WHITE);
		DrawTextEx(GetFontDefault(), "(", { 540, 14 }, 20, 5, WHITE);
		DrawTextEx(GetFontDefault(), ",", { 575, 14 }, 20, 5, WHITE);
		DrawTextEx(GetFontDefault(), ")", { 610, 14 }, 20, 5, WHITE);

		if (CheckCollisionPointRec(GetMousePosition(), textBoxX)) mouseOnTextX = true;
		else mouseOnTextX = false;
		if (mouseOnTextX)
		{
			SetMouseCursor(MOUSE_CURSOR_IBEAM);
			int keyX = GetCharPressed();
			while (keyX > 0)
			{
				if ((keyX >= 32) && (keyX <= 125) && (letterCountX < MAX_INPUT_CHARS_X))
				{
					nameX[letterCountX] = (char)keyX;
					nameX[letterCountX + 1] = '\0';
					letterCountX++;
				}
				keyX = GetCharPressed();
			}
			if (IsKeyPressed(KEY_BACKSPACE))
			{
				letterCountX--;
				if (letterCountX < 0) letterCountX = 0;
				nameX[letterCountX] = '\0';
			}
		}
		else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
		if (mouseOnTextX) framesCounterX++;
		else framesCounterX = 0;

		// ---------------------------------------------------------

		if (CheckCollisionPointRec(GetMousePosition(), textBoxY)) mouseOnTextY = true;
		else mouseOnTextY = false;
		if (mouseOnTextY)
		{
			SetMouseCursor(MOUSE_CURSOR_IBEAM);
			int keyY = GetCharPressed();
			while (keyY > 0)
			{
				if ((keyY >= 32) && (keyY <= 125) && (letterCountY < MAX_INPUT_CHARS_Y))
				{
					nameY[letterCountY] = (char)keyY;
					nameY[letterCountY + 1] = '\0';
					letterCountY++;
				}
				keyY = GetCharPressed();
			}
			if (IsKeyPressed(KEY_BACKSPACE))
			{
				letterCountY--;
				if (letterCountY < 0) letterCountY = 0;
				nameY[letterCountY] = '\0';
			}
		}
		else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
		if (mouseOnTextY) framesCounterY++;
		else framesCounterY = 0;

		// ---------------------------------------------------------
		if (CheckCollisionPointRec(GetMousePosition(), submitButton)) mouseOnSubmitButton = true;
		else mouseOnSubmitButton = false;
		if (mouseOnSubmitButton)
		{
			SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				cout << "Submit button pressed" << endl;
				drawVector4 = true;
			}
		}


		BeginDrawing();
		ClearBackground(BLACK);
		CustomRaylib::PlotGrids(screenWidth, screenHeight);
		CustomRaylib::PlotThickOriginVector2D(screenWidth, screenHeight, particle1.getXPosition(), particle1.getYPosition(), PINK, normalizedForce1);
		CustomRaylib::WriteLegend(10, 10, "Vector 1", PINK);
		CustomRaylib::PlotThickOriginVector2D(screenWidth, screenHeight, particle2.getXPosition(), particle2.getYPosition(), RED, normalizedForce2);
		CustomRaylib::WriteLegend(10, 30, "Vector 2", RED);
		CustomRaylib::PlotThickOriginVector2D(screenWidth, screenHeight, particle3.getXPosition(), particle3.getYPosition(), ORANGE, normalizedForce3);
		CustomRaylib::WriteLegend(10, 50, "Vector 3", ORANGE);
		CustomRaylib::PlotThickOriginVector2D(screenWidth, screenHeight, R.x, R.y, GREEN, normalizedForceR);
		CustomRaylib::WriteLegend(10, 70, "Vector R", BLUE);
		if (drawVector4) {
			int posX = std::stoi(nameX);
			int posY = std::stoi(nameY);
			Vector2Particle particle4 = Vector2Particle(Vector2D(posX, posY), 100);
			cout << particle4.getXPosition() << endl;
			cout << particle4.getYPosition() << endl;
			CustomRaylib::PlotThickOriginVector2D(screenWidth, screenHeight, particle4.getXPosition(), particle4.getYPosition(), PINK, 1);
			CustomRaylib::WriteLegend(10, 90, "Vector 4", PINK);
		}
		
		DrawRectangleRec(textBoxX, LIGHTGRAY);
		if (mouseOnTextX) DrawRectangleLines((int)textBoxX.x, (int)textBoxX.y, (int)textBoxX.width, (int)textBoxX.height, RED);
		else DrawRectangleLines((int)textBoxX.x, (int)textBoxX.y, (int)textBoxX.width, (int)textBoxX.height, DARKGRAY);
		DrawTextEx(GetFontDefault(), nameX, {textBoxX.x + 5, textBoxX.y + 8}, 20, 5, MAROON);
		
		DrawRectangleRec(textBoxY, LIGHTGRAY);
		if (mouseOnTextY) DrawRectangleLines((int)textBoxY.x, (int)textBoxY.y, (int)textBoxY.width, (int)textBoxY.height, RED);
		else DrawRectangleLines((int)textBoxY.x, (int)textBoxY.y, (int)textBoxY.width, (int)textBoxY.height, DARKGRAY);
		DrawTextEx(GetFontDefault(), nameY, {textBoxY.x + 5, textBoxY.y + 8}, 20, 5, MAROON);

		DrawRectangleRec(submitButton, LIGHTGRAY);
		if (mouseOnSubmitButton) DrawRectangleLines((int)submitButton.x, (int)submitButton.y, (int)submitButton.width, (int)submitButton.height, RED);
		else DrawRectangleLines((int)submitButton.x, (int)submitButton.y, (int)submitButton.width, (int)submitButton.height, DARKGRAY);
		DrawTextEx(GetFontDefault(), "Submit", {submitButton.x + 12, submitButton.y + 8}, 10, 5, MAROON);

		EndDrawing();
	}


	CloseWindow();
	return 0;
}

bool IsAnyKeyPressed()
{
	bool keyPressed = false;
	int key = GetKeyPressed();

	if ((key >= 32) && (key <= 126)) keyPressed = true;

	return keyPressed;
}