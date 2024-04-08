#include <assert.h>
#include "vector3_particle.h"
using namespace cyclone;

void Vector3Particle::integrate(real duration)
{
    assert(duration > 0.0);
    // Update linear position.
    position.addScaledVector(velocity, duration);
    // Work out the acceleration from the force.
    Vector3 resultingAcc = acceleration;
    resultingAcc.addScaledVector(forceAccum, inverseMass);
    // Update linear velocity from the acceleration.
    velocity.addScaledVector(resultingAcc, duration);
    // Impose drag.
    velocity *= real_pow(damping, duration);
    // Clear the forces.
    clearAccumulator();
}

void Vector3Particle::clearAccumulator()
{
    forceAccum.clear();
}

void Vector3Particle::addForce(const Vector3& force)
{
    forceAccum += force;
}