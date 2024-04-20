#include <iostream>
#include <cmath>
#include "vector2_particle.h"
using namespace std;
using namespace cyclone;


int main() {

	Vector2Particle particle = Vector2Particle(Vector2(-3, 4), 250);
	float angle = particle.getAngle();
	cout << "Angle: " << angle << endl;
	cout << "X Coordinate: " << particle.getXCoordinate() << endl;
	cout << "Y Coordinate: " << particle.getYCoordinate() << endl;

	Vector2Particle particle2 = Vector2Particle(Vector2(1, 0), 50);
	float angle2 = particle2.getAngle();
	cout << "Angle: " << angle2 << endl;
	cout << "X Coordinate: " << particle2.getXCoordinate() << endl;
	cout << "Y Coordinate: " << particle2.getYCoordinate() << endl;

	Vector2Particle particle3 = Vector2Particle(Vector2(0, -2), 120);
	float angle3 = particle3.getAngle();
	cout << "Angle: " << angle3 << endl;
	cout << "X Coordinate: " << particle3.getXCoordinate() << endl;
	cout << "Y Coordinate: " << particle3.getYCoordinate() << endl;

	float Rx = particle.getXCoordinate() + particle2.getXCoordinate() + particle3.getXCoordinate();
	float Ry = particle.getYCoordinate() + particle2.getYCoordinate() + particle3.getYCoordinate();

	cout << "Rx: " << Rx << endl;
	cout << "Ry: " << Ry << endl;

	float R = sqrt(Rx * Rx + Ry * Ry);
	cout << "R: " << R << endl;

	float angle4 = atan2(Ry, Rx);
	cout << "Angle: " << angle4 * 180 / 3.14159 << endl;

	return 0;
}