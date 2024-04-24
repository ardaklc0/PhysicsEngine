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
#define MAX_INPUT_CHARS_X 2
#define MAX_INPUT_CHARS_Y 2


Vector2Particle particle1 = Vector2Particle(Vector2D(0, 0), 0);
Vector2Particle particle2 = Vector2Particle(Vector2D(0, 0), 0);
Vector2Particle particle3 = Vector2Particle(Vector2D(0, 0), 0);
Vector2Particle particle4 = Vector2Particle(Vector2D(0, 0), 0);
Vector2Particle particle5 = Vector2Particle(Vector2D(0, 0), 0);
Vector2Particle particle6 = Vector2Particle(Vector2D(0, 0), 0);
Vector2Particle particle7 = Vector2Particle(Vector2D(0, 0), 0);
Vector2D R = particle1.getPosition() + particle2.getPosition() + particle3.getPosition() + particle4.getPosition() + particle5.getPosition() + particle6.getPosition() + particle7.getPosition();
Vector2Particle particleR = Vector2Particle(R, 0);


int main() {
	const int screenWidth = 650;
	const int screenHeight = 650;
	
	InitWindow(screenWidth, screenHeight, "Test");
	
	char nameX[MAX_INPUT_CHARS_X + 1] = "\0";
	char nameY[MAX_INPUT_CHARS_Y + 1] = "\0";
	
	int letterCountX = 0;
	int letterCountY = 0;
	
	Rectangle textBoxX = { 545, 10, 30, 25 };
	Rectangle textBoxY = { 585, 10, 30, 25 };
	Rectangle submitButton = { 465, 40, 75, 25 };
	Rectangle deleteButton = { 545, 40, 75, 25 };

	bool mouseOnSubmitButton = false;
	bool mouseOnDeleteButton = false;
	bool mouseOnTextX = false;
	bool mouseOnTextY = false;

	int framesCounterX = 0;
	int framesCounterY = 0;
	int framesCounterSubmitButton = 0;
	int framesCounterDeleteButton = 0;

	int vectorNumber = 1;

	SetTargetFPS(60);


	while (!WindowShouldClose())
	{
		DrawTextEx(GetFontDefault(), "(x,y)=", { 467, 14 }, 20, 5, WHITE);
		DrawTextEx(GetFontDefault(), "(", { 540, 14 }, 20, 5, WHITE);
		DrawTextEx(GetFontDefault(), ",", { 576, 14 }, 20, 5, WHITE);
		DrawTextEx(GetFontDefault(), ")", { 615, 14 }, 20, 5, WHITE);

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
				switch (vectorNumber) {
					case 1: {
						int posX = std::stoi(nameX);
						int posY = std::stoi(nameY);
						particle1 = Vector2Particle(Vector2D(posX, posY), 100);
						R = particle1.getPosition() + particle2.getPosition() + particle3.getPosition() + particle4.getPosition() + 
							particle5.getPosition() + particle6.getPosition() + particle7.getPosition();
						particleR = Vector2Particle(R, 0);
						vectorNumber++;
						break;
					}
					case 2: {
						int posX = std::stoi(nameX);
						int posY = std::stoi(nameY);
						particle2 = Vector2Particle(Vector2D(posX, posY), 100);
						R = particle1.getPosition() + particle2.getPosition() + particle3.getPosition() + particle4.getPosition() +
							particle5.getPosition() + particle6.getPosition() + particle7.getPosition();
						particleR = Vector2Particle(R, 0);
						vectorNumber++;
						break;
					}
					case 3: {
						int posX = std::stoi(nameX);
						int posY = std::stoi(nameY);
						particle3 = Vector2Particle(Vector2D(posX, posY), 100);
						R = particle1.getPosition() + particle2.getPosition() + particle3.getPosition() + particle4.getPosition() + 
							particle5.getPosition() + particle6.getPosition() + particle7.getPosition();
						particleR = Vector2Particle(R, 0);
						vectorNumber++;
						break;
					}
					case 4: {
						int posX = std::stoi(nameX);
						int posY = std::stoi(nameY);
						particle3 = Vector2Particle(Vector2D(posX, posY), 100);
						R = particle1.getPosition() + particle2.getPosition() + particle3.getPosition() + particle4.getPosition() +
							particle5.getPosition() + particle6.getPosition() + particle7.getPosition();
						particleR = Vector2Particle(R, 0);
						vectorNumber++;
						break;
					}
					case 5: {
						int posX = std::stoi(nameX);
						int posY = std::stoi(nameY);
						particle3 = Vector2Particle(Vector2D(posX, posY), 100);
						R = particle1.getPosition() + particle2.getPosition() + particle3.getPosition() + particle4.getPosition() + 
							particle5.getPosition() + particle6.getPosition() + particle7.getPosition();
						particleR = Vector2Particle(R, 0);
						vectorNumber++;
						break;
					}
					case 6: {
						int posX = std::stoi(nameX);
						int posY = std::stoi(nameY);
						particle3 = Vector2Particle(Vector2D(posX, posY), 100);
						R = particle1.getPosition() + particle2.getPosition() + particle3.getPosition() + particle4.getPosition() + 
							particle5.getPosition() + particle6.getPosition() + particle7.getPosition();
						particleR = Vector2Particle(R, 0);
						vectorNumber++;
						break;
					}
					case 7: {
						int posX = std::stoi(nameX);
						int posY = std::stoi(nameY);
						particle3 = Vector2Particle(Vector2D(posX, posY), 100);
						R = particle1.getPosition() + particle2.getPosition() + particle3.getPosition() + particle4.getPosition() + 
							particle5.getPosition() + particle6.getPosition() + particle7.getPosition();
						particleR = Vector2Particle(R, 0);
						vectorNumber++;
						break;
					}
				}
			}
		}

		if (CheckCollisionPointRec(GetMousePosition(), deleteButton)) mouseOnDeleteButton = true;
		else mouseOnDeleteButton = false;
		if (mouseOnDeleteButton) {
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				nameX[0] = '\0';
				nameY[0] = '\0';
				letterCountX = 0;
				letterCountY = 0;
				vectorNumber = 1;
				particle1 = Vector2Particle(Vector2D(0, 0), 0);
				particle2 = Vector2Particle(Vector2D(0, 0), 0);
				particle3 = Vector2Particle(Vector2D(0, 0), 0);
				particle4 = Vector2Particle(Vector2D(0, 0), 0);
				particle5 = Vector2Particle(Vector2D(0, 0), 0);
				particle6 = Vector2Particle(Vector2D(0, 0), 0);
				particle7 = Vector2Particle(Vector2D(0, 0), 0);
				R = particle1.getPosition() + particle2.getPosition() + particle3.getPosition() + particle4.getPosition() + 
					particle5.getPosition() + particle6.getPosition() + particle7.getPosition();
				particleR = Vector2Particle(R, 0);
			}
		}


		BeginDrawing();

		ClearBackground(BLACK);
		CustomRaylib::PlotGrids(screenWidth, screenHeight);


		CustomRaylib::PlotThickOriginVector2D(screenWidth, screenHeight, particle1.getXPosition(), particle1.getYPosition(), PINK, 1);
		CustomRaylib::WriteLegend(10, 10, "Vector 1", PINK);
		
		CustomRaylib::PlotThickOriginVector2D(screenWidth, screenHeight, particle2.getXPosition(), particle2.getYPosition(), RED, 1);
		CustomRaylib::WriteLegend(10, 30, "Vector 2", RED);
		
		CustomRaylib::PlotThickOriginVector2D(screenWidth, screenHeight, particle3.getXPosition(), particle3.getYPosition(), ORANGE, 1);
		CustomRaylib::WriteLegend(10, 50, "Vector 3", ORANGE);

		CustomRaylib::PlotThickOriginVector2D(screenWidth, screenHeight, particle3.getXPosition(), particle4.getYPosition(), BLUE, 1);
		CustomRaylib::WriteLegend(10, 70, "Vector 4", BLUE);

		CustomRaylib::PlotThickOriginVector2D(screenWidth, screenHeight, particle3.getXPosition(), particle5.getYPosition(), YELLOW, 1);
		CustomRaylib::WriteLegend(10, 90, "Vector 5", YELLOW);

		CustomRaylib::PlotThickOriginVector2D(screenWidth, screenHeight, particle3.getXPosition(), particle6.getYPosition(), GRAY, 1);
		CustomRaylib::WriteLegend(10, 110, "Vector 6", GRAY);

		CustomRaylib::PlotThickOriginVector2D(screenWidth, screenHeight, particle3.getXPosition(), particle7.getYPosition(), VIOLET, 1);
		CustomRaylib::WriteLegend(10, 130, "Vector 7", VIOLET);
	
		
		
		CustomRaylib::PlotThickOriginVector2D(screenWidth, screenHeight, R.x, R.y, GREEN, 1);
		CustomRaylib::WriteLegend(10, 150, "Vector R", GREEN);
		
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

		DrawRectangleRec(deleteButton, LIGHTGRAY);
		if (mouseOnDeleteButton) DrawRectangleLines((int)deleteButton.x, (int)deleteButton.y, (int)deleteButton.width, (int)deleteButton.height, RED);
		else DrawRectangleLines((int)deleteButton.x, (int)deleteButton.y, (int)deleteButton.width, (int)deleteButton.height, DARKGRAY);
		DrawTextEx(GetFontDefault(), "Delete", {deleteButton.x + 12, deleteButton.y + 8}, 10, 5, MAROON);

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