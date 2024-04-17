#include "precision.h"
#include "vector2.h"
#include <iostream>

namespace cyclone
{
	class Matrix2
	{
	public:
		// The values of the matrix.
		float data[4];

		// The default constructor creates a matrix with no rotation.
		Matrix2() :
			data{ 1, 0, 0, 1 } {}

		// The explicit constructor creates a matrix with the given components.
		Matrix2(const float data[4]) :
			data{ data[0], data[1], data[2], data[3] } {}

		// The explicit constructor creates a matrix with the given components.
		Matrix2(const float a, const float b, const float c, const float d) :
			data{ a, b, c, d } {}

		// Sets the matrix to be the identity matrix.
		void setIdentity()
		{
			data[0] = 1; data[1] = 0;
			data[2] = 0; data[3] = 1;
		}

		// Sets the matrix to be a rotation matrix.
		void setRotate(const float radians)
		{
			const float c = real_cos(radians);
			const float s = real_sin(radians);

			data[0] = c;
			data[1] = -s;
			data[2] = s;
			data[3] = c;
		}

		// Multiplies this matrix by another matrix.
		void operator*=(const Matrix2& matrix)
		{
			*this = *this * matrix;
		}

		// Multiplies a matrix by another matrix.
		Matrix2 operator*(const Matrix2& matrix) const
		{
			return Matrix2(data[0] * matrix.data[0] + data[1] * matrix.data[2],
				data[0] * matrix.data[1] + data[1] * matrix.data[3],
				data[2] * matrix.data[0] + data[3] * matrix.data[2],
				data[2] * matrix.data[1] + data[3] * matrix.data[3]);
		}

		float determinant() const
		{
			return data[0] * data[3] - data[1] * data[2];
		}

		Matrix2 operator*(float scaler) const
		{
			return Matrix2(data[0] * scaler, data[1] * scaler, data[2] * scaler, data[3] * scaler);
		}

		void setInverse()
		{
			float det = determinant();
			if (det == 0) return;
			float invDet = 1.0f / det;
			float temp = data[0];
			data[0] = -data[3];
			data[1] = data[1];
			data[2] = data[2];
			data[3] = -temp;
			*this = *this * invDet;
		}

		float operator[](int i) const
		{
			return data[i];
		}
	};
}