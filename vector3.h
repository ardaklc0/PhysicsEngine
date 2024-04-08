#include "precision.h"

namespace cyclone
{
    class Vector3
    {
    public:
        // Holds the value along the x axis.
        real x;

        // Holds the value along the y axis.
        real y;

        // Holds the value along the z axis.
        real z;
    private:
        // Padding to ensure 4 word alignment.
        real pad;

    public:
        // The default constructor creates a zero vector.
        Vector3() : x(0), y(0), z(0) {}

        // The explicit constructor creates a vector with the given components.
        Vector3(const real x, const real y, const real z) :
            x(x), y(y), z(z) {}

        // Inverts this vector and returns a reference to it.
        void invert()
        {
            x = -x;
            y = -y;
            z = -z;
        }

        // Gets the magnitude of this vector.
        real magnitude() const
        {
            return real_sqrt(x * x + y * y + z * z);
        }

        // Gets the squared magnitude of this vector.
        real squareMagnitude() const
        {
            return x * x + y * y + z * z;
        }

        // Overload of the addition-assign to scale a vector.
        void operator*=(const real scalar)
        {
            x *= scalar;
            y *= scalar;
            z *= scalar;
        }

        // Overload of the multiply operator to scale a vector.
        Vector3 operator*(const real& scalar) const
        {
            return Vector3(x * scalar, y * scalar, z * scalar);
        }

        // Overload of the addition-assign to add a vector.
        void operator+=(const Vector3& vector)
        {
            x += vector.x;
            y += vector.y;
            z += vector.z;
        }

        // Overload of the addition operator to add two vectors.
        Vector3 operator+(const Vector3& vector) const
        {
            return Vector3(x + vector.x, y + vector.y, z + vector.z);
        }

        // Overload of the subtraction-assign to subtract a vector.
        void operator-=(const Vector3& vector)
        {
            x -= vector.x;
            y -= vector.y;
            z -= vector.z;
        }

        // Overload of the subtraction operator to subtract two vectors.
        Vector3 operator-(const Vector3& vector) const
        {
            return Vector3(x - vector.x, y - vector.y, z - vector.z);
        }


        // Adds the given vector to this, scaled by the given amount.
        void addScaledVector(const Vector3& vector, real scale)
        {
            x += vector.x * scale;
            y += vector.y * scale;
            z += vector.z * scale;
        }

        // Calculates and returns the dot product of this vector with the given vector.
        Vector3 componentProduct(const Vector3& vector) const
        {
            return Vector3(x * vector.x, y * vector.y, z * vector.z);
        }

        void componentProductUpdate(const Vector3& vector)
        {
            x *= vector.x;
            y *= vector.y;
            z *= vector.z;
        }


        real scalarProduct(const Vector3& vector) const
        {
            return x * vector.x + y * vector.y + z * vector.z;
        }

        real operator*(const Vector3& vector) const {
            return x * vector.x + y * vector.y + z * vector.z;
        }

        real angleBetweenVectorsInRadians(const Vector3& vector) const
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

        real angleBetweenVectorsInDegrees(const Vector3& vector) const
        {
            return angleBetweenVectorsInRadians(vector) * 180 / 3.14159268f;
        }

        Vector3 vectorProduct(const Vector3& vector) const
        {
            return Vector3(y * vector.z - z * vector.y,
                z * vector.x - x * vector.z,
                x * vector.y - y * vector.x);
        }

        void operator %=(const Vector3& vector)
        {
            *this = vectorProduct(vector);
        }
        Vector3 operator%(const Vector3& vector) const
        {
            return Vector3(y * vector.z - z * vector.y,
                z * vector.x - x * vector.z,
                x * vector.y - y * vector.x);
        }

        void clear()
        {
            x = y = z = 0;
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
