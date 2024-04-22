#include "vector2.h"

#ifndef Vector2D_particle_h
#define Vector2D_particle_h
class Vector2Particle {
private:
    Vector2D position;
    float newton;
    float mass;
    float velocity;
    float friction;
public:
    Vector2Particle() : position(Vector2D(0, 0)), newton(0), mass(0), velocity(0), friction(0) {}

    Vector2Particle(Vector2D position) : position(position), newton(0), mass(0), velocity(0), friction(0) {}

    Vector2Particle(Vector2D position, float newton) :
        position(position), newton(newton) {}

    Vector2Particle(Vector2D position, float newton, float mass) :
        position(position), newton(newton), mass(mass) {}

    Vector2Particle(Vector2D position, float newton, float mass, float velocity) :
        position(position), newton(newton), mass(mass), velocity(velocity) {}

    Vector2Particle(Vector2D position, float newton, float mass, float velocity, float friction) :
        position(position), newton(newton), mass(mass), velocity(velocity), friction(friction) {}


    void setNewton(float newton);
    float getNewton() const;
    void setPosition(const Vector2D& position);
    Vector2D getPosition() const;
    float getAngle() const;
    float getXCoordinate() const;
    float getYCoordinate() const;
    float getMass() const;
    void setMass(float mass);
    float getVelocity() const;
    void setVelocity(float velocity);
    float getFriction() const;
    void setFriction(float friction);
};
#endif // !Vector2D_h

