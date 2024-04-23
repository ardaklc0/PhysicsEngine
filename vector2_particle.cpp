#include <assert.h>
#include "vector2_particle.h"

void Vector2Particle::setNewton(float newton)
{
	this->newton = newton;
}

float Vector2Particle::getNewton() const
{
	return newton;
}

void Vector2Particle::setPosition(const Vector2D& position)
{
	this->position = position;
}

Vector2D Vector2Particle::getPosition() const
{
	return position;
}

float Vector2Particle::getAngle() const
{
	return atan2(position.y, position.x);
}

float Vector2Particle::getXPosition() const
{
	return position.x;
}

float Vector2Particle::getYPosition() const
{
	return position.y;
}

float Vector2Particle::getXForce() const
{
	float angle = getAngle();
	float xCoordinate = newton * cos(angle);
	return xCoordinate;
}

float Vector2Particle::getYForce() const
{
	float angle = getAngle();
	float yCoordinate = newton * sin(angle);
	return yCoordinate;
}

float Vector2Particle::getMass() const
{
	return mass;
}

void Vector2Particle::setMass(float mass)
{
	this->mass = mass;
}

float Vector2Particle::getVelocity() const
{
	return velocity;
}

void Vector2Particle::setVelocity(float velocity)
{
	this->velocity = velocity;
}

float Vector2Particle::getFriction() const
{
	return friction;
}

void Vector2Particle::setFriction(float friction)
{
	this->friction = friction;
}