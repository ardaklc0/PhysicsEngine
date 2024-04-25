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

float freeFall(float t, float y, float y_prime) {
	// y'' = -g
	return -9.68;
}

int main() {
	const int screenWidth = 650;
	const int screenHeight = 650;
	
	InitWindow(screenWidth, screenHeight, "Test");
	SetTargetFPS(60);

	SecondOrderEulerMethod second_order_euler = SecondOrderEulerMethod(0, 50, 0, 0.01);
	second_order_euler.solve(1000, freeFall);



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
