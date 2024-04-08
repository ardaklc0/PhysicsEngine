#include <iostream>
#include "vector2_particle.h"
using namespace cyclone;

using namespace std;

int main() {
	Vector2 gravity = Vector2(0, -9.80665);
	Vector2 positionVector = Vector2(0, 50); // y_0 = 50
	Vector2 velocityVector = Vector2(0, 10); // v_0 = 10
	Vector2 accelerationVector = gravity;

	real damping = 0.99f;
	real inverseMass = 1.0 / 1.0; // m = 1.0

	Vector2Particle particle = Vector2Particle();
	particle.position = positionVector;
	particle.velocity = velocityVector;
	particle.acceleration = accelerationVector;
	particle.damping = damping;
	particle.inverseMass = inverseMass;

	cout << "Initial position: " << "(" <<
		particle.position.x << ", " << 
		particle.position.y << ")" << endl;

	cout << "Initial velocity: " << "(" <<
		particle.velocity.x << ", " << 
		particle.velocity.y << ")" << endl;

	cout << "Initial acceleration: " << "(" <<
		particle.acceleration.x << ", " << 
		particle.acceleration.y << ")" << endl;

	cout << "Initial damping: " <<
		particle.damping << endl;

	cout << "Initial inverse mass: " << 
		particle.inverseMass << endl;

	return 0;
}