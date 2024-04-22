#include "Vector2.h"
#include "vector3.h"
using namespace cyclone;
class EulerMethodMultiVariable
{
	public:
		float h;
		float t0;
		Vector2D initialCoordinates2D;
		Vector3 initialCoordinates3D;

		EulerMethodMultiVariable(float t0, Vector2D initialCoordinates2D, float h) :
			h(h), t0(t0), initialCoordinates2D(initialCoordinates2D) {}

		float solve(int n, float(*func)(float, float)) const;
};