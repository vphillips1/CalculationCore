#include "algebra.h"
#include<math.h>

// Solve Quadratic Formula
int Algebra::calculateQuadratic(double a, double b, double c, Complex roots[2])
{
	if (a == 0)
	{
		if (b == 0)
		{
			return 0;
		}

		roots[0].realNumber = -c / b;
		roots[0].imagineryNumber = 0;
		return 1;
	}

	double discriminant = b * b - 4 * a * c;
	if (discriminant >= 0)
	{
		double sqrt_disc = sqrt(discriminant);
		roots[0].realNumber = (-b + sqrt_disc) / (2 * a);
		roots[0].imagineryNumber = 0;
		roots[1].realNumber = (-b - sqrt_disc) / (2 * a);
		roots[1].imagineryNumber = 0;
	}
	else
	{
		double sqrt_disc = sqrt(-discriminant);
		roots[0].realNumber = -b / (2 * a);
		roots[0].imagineryNumber = sqrt_disc / (2 * a);
		roots[1].realNumber = -b / (2 * a);
		roots[1].imagineryNumber = -sqrt_disc / (2 * a);
	}
	return 2;
}

//Slope-Intercept Form
Line Algebra::slopeInterceptForm(double x1, double y1, double x2, double y2)
{
	Line result;
	if (x1 == x2)
	{
		result.slope = 1e308;
		result.intercept = 0;
	}
	else
	{
		result.slope = (y2 - y1) / (x2 - x1);
		result.intercept = y1 - result.slope * x1;
	}
	return result;
}

//Point-slope Form
double Algebra::pointSlopeForm(double x1, double y1, double slope, double x)
{
	return slope * (x - x1) + y1;
}

//Rectangle Perimeter
double Algebra::rectanglePerimeter(double width, double height)
{
	if (width < 0) width = -width;
	if (height < 0) height = -height;
	return 2 * (width + height);
}

//Triangle Perimeter
double Algebra::trianglePerimeter(double a, double b, double c)
{
	if (a < 0)
	{
		a = -a;
	}
	if (b < 0)
	{
		b = -b;
	}
	if (c < 0)
	{
		c = -c;
	}

	return a + b + c;
}