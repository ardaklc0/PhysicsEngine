#include "vector2.h"
using namespace cyclone;

class Vector2Particle {
public:
    // Holds the linear position of the particle in the world.
    Vector2 position;

    // Holds the linear velocity of the particle in the world.
    Vector2 velocity;

    // Holds the acceleration of the particle.
    Vector2 acceleration;

    // Holds the accumulated force to be applied at the next simulation iteration only.
    Vector2 forceAccum;

    // Holds the amount of damping applied to linear motion.
    real damping;

    // Holds the inverse of the mass of the particle. 
    // It is more useful to hold the inverse mass because integration is simpler.
    real inverseMass;

    // Integrates the particle forward in time by the given amount.
    void integrate(real duration);
    void clearAccumulator();
    void addForce(const cyclone::Vector2& force);
};