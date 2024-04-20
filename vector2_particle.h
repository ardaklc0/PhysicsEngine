#include "vector2.h"
using namespace cyclone;

class Vector2Particle {
private:
    // Holds the linear position of the particle in the world.
    Vector2 position;

    // Holds the newton
    float newton;
public:
    Vector2Particle(Vector2 position, float newton) : 
        position(position), newton(newton) {}

    void setNewton(float newton);
    float getNewton() const;
    void setPosition(const Vector2& position);
    Vector2 getPosition() const;
    float getAngle() const;
    float getXCoordinate() const;
    float getYCoordinate() const;
};