#include <iostream>
#include "vector2.h"
#include <cmath>
using namespace std;
#include <fstream>

Vector2 coordinates(float t) {
	return Vector2(2 - 0.25 * pow(t, 2), t + 0.025 * pow(t, 3));
}

int roverPathAnalyticSolution() {
	/*
	* x = 2 - 0.25 * t^2
	* y = t + 0.025 * t^3
	*
	* A robotic vehicle, or rover, is exploring the surface of Mars.
	The stationary Mars lander is the origin of coordinates,
	and the surrounding Martian surface lies in the xy-plane. The rover, which we
	represent as a point, has x- and y-coordinates that vary with time:
	(a) Find the rover’s coordinates and distance from the lander at t = 2.0 s.
	(b) Find the rover’s displacement and average velocity
	vectors for the interval t = 0 to t = 2 (c) Find a general
	expression for the rover’s instantaneous velocity vector v. Express v
	at in component form and in terms of magnitude and direction.
	*/
	int counter = 0;
	float step = 0.001;
	float time = 10;
	ofstream roversPath;
	roversPath.open("roversPath.txt");
	for (float i = 0; i <= time; i += step) {
		Vector2 coordinatesOfRover = coordinates(i);
		if (counter % (int)(step * 10000) == 0) {
			cout << "Coordinates of the rover at t = " << i << " -> " << "(" << coordinatesOfRover.x << ", " << coordinatesOfRover.y << ")" << endl;
			roversPath << "Coordinates of the rover at t = " << i << " -> " << "(" << coordinatesOfRover.x << ", " << coordinatesOfRover.y << ")" << endl;

			float distance = coordinatesOfRover.magnitude();
			cout << "Distance from the lander at t = " << i << " -> " << distance << endl;
			roversPath << "Distance from the lander at t = " << i << " -> " << distance << endl;

			Vector2 displacementAtZero = coordinates(i);
			cout << "Displacement of the rover at t = " << i << " -> " << "(" << displacementAtZero.x << ", " << displacementAtZero.y << ")" << endl;
			roversPath << "Displacement of the rover at t = " << i << " -> " << "(" << displacementAtZero.x << ", " << displacementAtZero.y << ")" << endl;

			Vector2 displacementAtTwo = coordinates(i + step);
			cout << "Displacement of the rover at t = " << i + step << " -> " << "(" << displacementAtTwo.x << ", " << displacementAtTwo.y << ")" << endl;
			roversPath << "Displacement of the rover at t = " << i + step << " -> " << "(" << displacementAtTwo.x << ", " << displacementAtTwo.y << ")" << endl;

			Vector2 totalDisplacement = (displacementAtTwo - displacementAtZero);
			cout << "Total Displacement of the rover from t =" << i << "to t = " << i + step << " -> " << "(" << totalDisplacement.x << ", " << totalDisplacement.y << ")" << endl;
			roversPath << "Total Displacement of the rover from t =" << i << "to t = " << i + step << " -> " << "(" << totalDisplacement.x << ", " << totalDisplacement.y << ")" << endl;

			Vector2 averageVelocity = totalDisplacement / step;
			cout << "Velocity of the rover from t =" << i << " to t = " << i + step << " -> " << "(" << averageVelocity.x << ", " << averageVelocity.y << ")" << endl;
			roversPath << "Velocity of the rover from t =" << i << " to t = " << i + step << " -> " << "(" << averageVelocity.x << ", " << averageVelocity.y << ")" << endl;

			float angleBetween = atan(averageVelocity.y / averageVelocity.x);
			cout << "Angle between the velocity vector and the x-axis at t = " << i << " -> " << 180 - (angleBetween * 180 / 3.14159265359) << " degrees" << endl;
			roversPath << "Angle between the velocity vector and the x-axis at t = " << i << " -> " << 180 - (angleBetween * 180 / 3.14159265359) << " degrees" << endl;

			cout << "-----------------------------------" << endl;
			roversPath << "-----------------------------------" << endl;
		}
		if (coordinatesOfRover.x < 0 || coordinatesOfRover.y < 0) {
			roversPath.close();
			break;
		}
		counter++;
	}

	return 0;
}