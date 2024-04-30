#include <raylib.h>
class CustomRaylib 
{
public:
	static void PlotAxis(float screenWidth, float screenHeight);
	static void PlotOriginVector2D(float screenWidth, float screenHeight, float x, float y, Color color);
	static void WriteLegend(float x, float y, const char *legend, Color color);
	static void PlotThickOriginVector2D(float screenWidth, float screenHeight, float x, float y, Color color, float thickness);
	static void PlotDistanceRuler(float screenWidth, float screenHeight);
	static void PlotDistanceRulerProjectile(float screenWidth, float screenHeight);

	CustomRaylib() = delete;
};