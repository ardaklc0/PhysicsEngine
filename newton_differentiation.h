class NewtonDifferentiation {
public:
	float h;
	float x;
	
	NewtonDifferentiation(float x, float h = 1) :
		x(x), h(h) {}

	float solve(int n, float(*func)(float)) const;

};
