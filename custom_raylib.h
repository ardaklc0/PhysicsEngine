#include <raylib.h>
class CustomRaylib 
{
public:
	static void PlotGrids(float screenWidth, float screenHeight);
	static void PlotOriginVector2D(float screenWidth, float screenHeight, float x, float y, Color color);

	CustomRaylib() = delete;
};