#include <assert.h>
#include "vector2_particle.h"
using namespace cyclone;


void Vector2Particle::setNewton(float newton)
{
	this->newton = newton;
}

float Vector2Particle::getNewton() const
{
	return newton;
}

void Vector2Particle::setPosition(const Vector2& position)
{
	this->position = position;
}

Vector2 Vector2Particle::getPosition() const
{
	return position;
}

float Vector2Particle::getAngle() const
{
	return atan2(position.y, position.x);
}

float Vector2Particle::getXCoordinate() const
{
	float angle = getAngle();
	float xCoordinate = newton * cos(angle);
	return xCoordinate;
}

float Vector2Particle::getYCoordinate() const
{
	float angle = getAngle();
	float yCoordinate = newton * sin(angle);
	return yCoordinate;
}

