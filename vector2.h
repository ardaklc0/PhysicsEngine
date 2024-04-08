#include "precision.h"

namespace cyclone
{
    class Vector2
    {
    public:
        // Holds the value along the x axis.
        real x;

        // Holds the value along the y axis.
        real y;

    private:
        // Padding to ensure 4 word alignment.
        real pad;

    public:
        // The default constructor creates a zero vector.
        Vector2() : x(0), y(0) {}

        // The explicit constructor creates a vector with the given components.
        Vector2(const real x, const real y) :
            x(x), y(y) {}

        // Inverts this vector and returns a reference to it.
        void invert()
        {
            x = -x;
            y = -y;
        }

        // Gets the magnitude of this vector.
        real magnitude() const
        {
            return real_sqrt(x * x + y * y);
        }

        // Gets the squared magnitude of this vector.
        real squareMagnitude() const
        {
            return x * x + y * y;
        }

        // Overload of the addition-assign to scale a vector.
        void operator*=(const real scalar)
        {
            x *= scalar;
            y *= scalar;
        }

        // Overload of the multiply operator to scale a vector.
        Vector2 operator*(const real& scalar) const
        {
            return Vector2(x * scalar, y * scalar);
        }

        // Overload of the addition-assign to add a vector.
        void operator+=(const Vector2& vector)
        {
            x += vector.x;
            y += vector.y;
        }

        // Overload of the addition operator to add two vectors.
        Vector2 operator+(const Vector2& vector) const
        {
            return Vector2(x + vector.x, y + vector.y);
        }

        // Overload of the subtraction-assign to subtract a vector.
        void operator-=(const Vector2& vector)
        {
            x -= vector.x;
            y -= vector.y;
        }

        // Overload of the subtraction operator to subtract two vectors.
        Vector2 operator-(const Vector2& vector) const
        {
            return Vector2(x - vector.x, y - vector.y);
        }


        // Adds the given vector to this, scaled by the given amount.
        void addScaledVector(const Vector2& vector, real scale)
        {
            x += vector.x * scale;
            y += vector.y * scale;
        }

        // Calculates and returns the dot product of this vector with the given vector.
        Vector2 componentProduct(const Vector2& vector) const
        {
            return Vector2(x * vector.x, y * vector.y);
        }

        void componentProductUpdate(const Vector2& vector)
        {
            x *= vector.x;
            y *= vector.y;
        }


        real scalarProduct(const Vector2& vector) const
        {
            return x * vector.x + y * vector.y;
        }

        real operator*(const Vector2& vector) const {
            return x * vector.x + y * vector.y;
        }

        real angleBetweenVectorsInRadians(const Vector2& vector) const
        {
            real dotProduct = *this * vector;
            real magnitudeProduct = (*this).magnitude() * vector.magnitude();
            if (magnitudeProduct == 0) {
                return 0;
            }
            else {
                return acos(dotProduct / magnitudeProduct);
            }
        }

        real angleBetweenVectorsInDegrees(const Vector2& vector) const
        {
            return angleBetweenVectorsInRadians(vector) * 180 / 3.14159268f;
        }

        void clear()
        {
            x = y = 0;
        }

        // We decided to use the operator overload *= to scale the vector.
        void normalize()
        {
            real l = magnitude();
            if (l > 0)
            {
                (*this) *= 1 / l;
            }
        }
    };
}
