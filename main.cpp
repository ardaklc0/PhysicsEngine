#include <iostream>
#include <cmath>
#include "vector2_particle.h"
#include "second_order_euler_method.h"
#include "euler_method.h"
#include "newton_differentiation.h"
#include "vector2.h"
#include <raylib.h>
#include "custom_raylib.h"
using namespace std;


int main() {
	const int screenWidth = 650;
	const int screenHeight = 650;
	InitWindow(screenWidth, screenHeight, "Test");
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
		EndDrawing();
	}


	CloseWindow();
	return 0;
}

