#include <iostream>
#include <cmath>
#include "vector2_particle.h"
using namespace std;


int netForceCalculator() {

	Vector2Particle particle1 = Vector2Particle(Vector2D(-3, 4), 250);
	Vector2Particle particle2 = Vector2Particle(Vector2D(1, 0), 50);
	Vector2Particle particle3 = Vector2Particle(Vector2D(0, -2), 120);

	float angle1 = particle1.getAngle();
	float angle2 = particle2.getAngle();
	float angle3 = particle3.getAngle();

	float Rx = particle1.getXCoordinate() + particle2.getXCoordinate() + particle3.getXCoordinate();
	float Ry = particle1.getYCoordinate() + particle2.getYCoordinate() + particle3.getYCoordinate();
	Vector2D R = Vector2D(Rx, Ry);

	float RMagnitude = R.magnitude();
	float angle4 = R.angleBetweenVectorsInDegrees();


	cout << "Angle = " << angle1 << endl;
	cout << "(x1, y1) = " << "(" << particle1.getXCoordinate() << ", " << particle1.getYCoordinate() << ")" << endl;

	cout << "Angle = " << angle2 << endl;
	cout << "(x2, y2) = " << "(" << particle2.getXCoordinate() << ", " << particle2.getYCoordinate() << ")" << endl;

	cout << "Angle = " << angle3 << endl;
	cout << "(x3, y3) = " << "(" << particle3.getXCoordinate() << ", " << particle3.getYCoordinate() << ")" << endl;


	cout << "(Rx, Ry) = " << "(" << R.x << ", " << R.y << ")" << endl;
	cout << "|R| = " << RMagnitude << endl;

	cout << "Angle: " << angle4 << endl;

	return 0;
}