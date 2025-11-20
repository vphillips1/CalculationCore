#ifndef ALGEBRA_H
#define ALGEBRA_H
#include <string>

using namespace std;

struct Complex {
	double realNumber;
	double imagineryNumber;
};

struct Line {
	double slope;
	double intercept;
};

class Algebra {

public:

	static int calculateQuadratic(double a, double b, double c, Complex roots[2]);
	static Line slopeInterceptForm(double x1, double y1, double x2, double y2);
	static double pointSlopeForm(double x1, double y1, double slope, double x);
	static double rectanglePerimeter(double width, double height);
	static double trianglePerimeter(double a, double b, double c);

};

#endif