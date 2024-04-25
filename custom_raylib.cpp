#include "custom_raylib.h"
#include <raylib.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;



void CustomRaylib::PlotAxis(float screenWidth, float screenHeight) {
	DrawLine(0, screenHeight / 2, screenWidth, screenHeight / 2, WHITE);
	DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);
	for (int i = -300; i <= 300; i += 60)
	{
		int index = i / 60;
		char str[10];
		sprintf_s(str, "%d", index);
		DrawCircle(screenWidth / 2 + i, screenHeight / 2, 3, WHITE);
		DrawText(str, screenWidth / 2 + i + 5, screenHeight / 2, 10, WHITE);
		if (i == 0)
			continue;
		sprintf_s(str, "%d", -index);
		DrawCircle(screenWidth / 2, screenHeight / 2 + i, 3, WHITE);
		DrawText(str, screenWidth / 2 + 5, screenHeight / 2 + i + 5, 10, WHITE);
	}
}

void CustomRaylib::PlotOriginVector2D(float screenWidth, float screenHeight, float x, float y, Color color) {
	DrawLine(screenWidth / 2, screenHeight / 2, screenWidth / 2 + x * 60, screenHeight / 2 - y * 60, color);
	DrawCircle(screenWidth / 2 + x * 60, screenHeight / 2 - y * 60, 3, color);
}

void CustomRaylib::WriteLegend(float x, float y, const char *text, Color color) {
	DrawTextEx(GetFontDefault(), text, { 10 + x, y }, 20, 5, WHITE);
	DrawCircle(x, y + 10, 5, color);
}

void CustomRaylib::PlotThickOriginVector2D(float screenWidth, float screenHeight, float x, float y, Color color, float thickness) {
	DrawLineEx({ screenWidth / 2, screenHeight / 2 }, { screenWidth / 2 + x * 60, screenHeight / 2 - y * 60 }, thickness, color);
	DrawCircle(screenWidth / 2 + x * 60, screenHeight / 2 - y * 60, 3, color);
}

void CustomRaylib::PlotDistanceRuler(float screenWidth, float screenHeight) {
	for (int i = 600; i > 0; i -= 60)
	{
		// Bars
		DrawLine(screenWidth / 3, i, screenWidth / 3 - 10, i, WHITE);
		// Vertical line
		DrawLineEx({ screenWidth / 3, 0}, {screenWidth / 3, screenHeight}, 2 , WHITE);
		// Horizontal line
		DrawLineEx({ 0, screenHeight }, { screenWidth, screenHeight },  2, WHITE);


		int index = (600 - i) / 6;
		char str[10];
		sprintf_s(str, "%d m", index);
		DrawText(str, screenWidth / 3 - 35, i - 15, 10, WHITE);


	}
}