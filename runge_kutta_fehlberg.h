class RungeKuttaFehlberg
{
public:
	float h;
	float t0;
	float y0;

	RungeKuttaFehlberg(float t0, float y0, float h = 1) :
		t0(t0), y0(y0), h(h) {}

	float solve(int n, float(*func)(float, float)) const;
};