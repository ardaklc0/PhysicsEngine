#include "vector2.h"

class Vector2Particle {
private:
    Vector2 position;
    float newton;
    float mass;
    float velocity;
    float friction;
public:
    Vector2Particle() : position(Vector2(0, 0)), newton(0), mass(0), velocity(0), friction(0) {}

    Vector2Particle(Vector2 position) : position(position), newton(0), mass(0), velocity(0), friction(0) {}

    Vector2Particle(Vector2 position, float newton) :
        position(position), newton(newton) {}

    Vector2Particle(Vector2 position, float newton, float mass) :
        position(position), newton(newton), mass(mass) {}

    Vector2Particle(Vector2 position, float newton, float mass, float velocity) :
		position(position), newton(newton), mass(mass), velocity(velocity) {}

    Vector2Particle(Vector2 position, float newton, float mass, float velocity, float friction) :
        position(position), newton(newton), mass(mass), velocity(velocity), friction(friction) {}


    void setNewton(float newton);
    float getNewton() const;
    void setPosition(const Vector2& position);
    Vector2 getPosition() const;
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