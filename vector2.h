#include "precision.h"

namespace cyclone
{
    class Vector2
    {
    public:
        // Holds the value along the x axis.
        float x;

        // Holds the value along the y axis.
        float y;

    private:
        // Padding to ensure 4 word alignment.
        float pad;

    public:
        // The default constructor creates a zero vector.
        Vector2() : x(0), y(0) {}

        // The explicit constructor creates a vector with the given components.
        Vector2(const float x, const float y) :
            x(x), y(y) {}

        // Inverts this vector and returns a reference to it.
        void invert()
        {
            x = -x;
            y = -y;
        }

        // Gets the magnitude of this vector.
        float magnitude() const
        {
            return real_sqrt(x * x + y * y);
        }

        // Gets the squared magnitude of this vector.
        float squareMagnitude() const
        {
            return x * x + y * y;
        }

        // Overload of the addition-assign to scale a vector.
        void operator*=(const float scalar)
        {
            x *= scalar;
            y *= scalar;
        }

        // Overload of the multiply operator to scale a vector.
        Vector2 operator*(const float& scalar) const
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

        Vector2 operator/(const float& scalar) const
		{
			return Vector2(x / scalar, y / scalar);
        }

        Vector2 operator/= (const float& scalar)
		{
			x /= scalar;
			y /= scalar;
			return *this;
		}

        float operator[](int i) const
        {
			if (i == 0) return x;
			else if (i == 1) return y;
			else return 0;
		}

        // Adds the given vector to this, scaled by the given amount.
        void addScaledVector(const Vector2& vector, float scale)
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


        float scalarProduct(const Vector2& vector) const
        {
            return x * vector.x + y * vector.y;
        }

        float operator*(const Vector2& vector) const {
            return x * vector.x + y * vector.y;
        }

        float angleBetweenVectorsInRadians(const Vector2& vector) const
        {
            float dotProduct = *this * vector;
            float magnitudeProduct = (*this).magnitude() * vector.magnitude();
            if (magnitudeProduct == 0) {
                return 0;
            }
            else {
                return acos(dotProduct / magnitudeProduct);
            }
        }

        float angleBetweenVectorsInDegrees(const Vector2& vector) const
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
            float l = magnitude();
            if (l > 0)
            {
                (*this) *= 1 / l;
            }
        }
    };
}
