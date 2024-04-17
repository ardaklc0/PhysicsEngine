#include "precision.h"
#include "vector2.h"
#include <iostream>

namespace cyclone
{
	class Matrix3
	{
		public:
			// The values of the matrix.
			float data[9];

			// The default constructor creates a matrix with no data in it.
			Matrix3() :
				data{1, 0, 0, 0, 1, 0, 0, 0, 1} {}
			
			// The constructor creates a matrix with specified values.
			Matrix3(const float data[9]) :
				data{data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8]} {}

			// The constructor creates a matrix with specified values.
			Matrix3(const float d0, const float d1, const float d2, const float d3, const float d4, const float d5, const float d6, const float d7, const float d8) :
				data{d0, d1, d2, d3, d4, d5, d6, d7, d8} {}

			// Sets the matrix to be the identity matrix.
			void setIdentity()
			{
				data[0] = 1; data[1] = 0; data[2] = 0;
				data[3] = 0; data[4] = 1; data[5] = 0;
				data[6] = 0; data[7] = 0; data[8] = 1;
			}

			Matrix3 operator*(const Matrix3& matrix) const
			{
				return Matrix3(
					data[0] * matrix.data[0] + data[1] * matrix.data[3] + data[2] * matrix.data[6],
					data[0] * matrix.data[1] + data[1] * matrix.data[4] + data[2] * matrix.data[7],
					data[0] * matrix.data[2] + data[1] * matrix.data[5] + data[2] * matrix.data[8],
					data[3] * matrix.data[0] + data[4] * matrix.data[3] + data[5] * matrix.data[6],
					data[3] * matrix.data[1] + data[4] * matrix.data[4] + data[5] * matrix.data[7],
					data[3] * matrix.data[2] + data[4] * matrix.data[5] + data[5] * matrix.data[8],
					data[6] * matrix.data[0] + data[7] * matrix.data[3] + data[8] * matrix.data[6],
					data[6] * matrix.data[1] + data[7] * matrix.data[4] + data[8] * matrix.data[7],
					data[6] * matrix.data[2] + data[7] * matrix.data[5] + data[8] * matrix.data[8]
				);
			}

			Matrix3 operator*=(const Matrix3& matrix) const
			{
				return *this * matrix;
			}

			float determinant() const
			{
				return data[0] * data[4] * data[8] + data[3] * data[7] * data[2] + data[6] * data[1] * data[5] - data[0] * data[7] * data[5] - data[3] * data[1] * data[8] - data[6] * data[4] * data[2];
			}

			void setInverse()
			{
				// Make sure the determinant is non-zero.
				float det = determinant();
				if (det == 0) return;
				det = 1.0f / det;
			}

			float operator[](const unsigned i) const
			{
				return data[i];
			}
	};
}