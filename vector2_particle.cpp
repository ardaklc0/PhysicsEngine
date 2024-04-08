#include <assert.h>
#include "vector2_particle.h"
using namespace cyclone;

void Vector2Particle::integrate(real duration)
{
    assert(duration > 0.0);
    // Update linear position.
    position.addScaledVector(velocity, duration);
    // Work out the acceleration from the force.
    Vector2 resultingAcc = acceleration;
    resultingAcc.addScaledVector(forceAccum, inverseMass);
    // Update linear velocity from the acceleration.
    velocity.addScaledVector(resultingAcc, duration);
    // Impose drag.
    velocity *= real_pow(damping, duration);
    // Clear the forces.
    clearAccumulator();
}

void Vector2Particle::clearAccumulator()
{
    forceAccum.clear();
}

void Vector2Particle::addForce(const Vector2& force)
{
    forceAccum += force;
}