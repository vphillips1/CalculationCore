#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "algebra.h"

using namespace std;

int main() {
    ifstream input("uncalculated-algebra.txt");
    ofstream output("calculated-algebra.txt");

    if (!input.is_open()) {
        cerr << "Error: Could not open uncalculated-algebra.txt\n";
        return 1;
    }
    if (!output.is_open()) {
        cerr << "Error: Could not open calculated-algebra.txt\n";
        return 1;
    }

    string line;

    while (getline(input, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string command;
        ss >> command;

        // QUADRATIC a b c
        if (command == "QUADRATIC") {
            double a, b, c;
            ss >> a >> b >> c;

            Complex roots[2];
            int rootCount = Algebra::calculateQuadratic(a, b, c, roots);

            cout << "QUADRATIC(" << a << ", " << b << ", " << c << "): ";
            output << "QUADRATIC(" << a << ", " << b << ", " << c << "): ";

            if (rootCount == 0) {
                cout << "No solution\n";
                output << "No solution\n";
            }
            else if (rootCount == 1) {
                cout << "1 root = " << roots[0].realNumber << "\n";
                output << "1 root = " << roots[0].realNumber << "\n";
            }
            else {
                cout << "roots = "
                    << roots[0].realNumber << " + " << roots[0].imagineryNumber << "i"
                    << ", "
                    << roots[1].realNumber << " + " << roots[1].imagineryNumber << "i\n";

                output << "roots = "
                    << roots[0].realNumber << " + " << roots[0].imagineryNumber << "i"
                    << ", "
                    << roots[1].realNumber << " + " << roots[1].imagineryNumber << "i\n";
            }
        }

        // SLOPE_INTERCEPT x1 y1 x2 y2
        else if (command == "SLOPE_INTERCEPT") {
            double x1, y1, x2, y2;
            ss >> x1 >> y1 >> x2 >> y2;

            Line line = Algebra::slopeInterceptForm(x1, y1, x2, y2);

            cout << "SLOPE_INTERCEPT slope = " << line.slope
                << ", intercept = " << line.intercept << "\n";

            output << "SLOPE_INTERCEPT slope = " << line.slope
                << ", intercept = " << line.intercept << "\n";
        }

        // POINT_SLOPE x1 y1 slope x
        else if (command == "POINT_SLOPE") {
            double x1, y1, slope, x;
            ss >> x1 >> y1 >> slope >> x;

            double y = Algebra::pointSlopeForm(x1, y1, slope, x);

            cout << "POINT_SLOPE y = " << y << "\n";
            output << "POINT_SLOPE y = " << y << "\n";
        }

        // RECTANGLE_PERIMETER width height
        else if (command == "RECTANGLE_PERIMETER") {
            double width, height;
            ss >> width >> height;

            double per = Algebra::rectanglePerimeter(width, height);
            cout << "RECTANGLE_PERIMETER = " << per << "\n";
            output << "RECTANGLE_PERIMETER = " << per << "\n";
        }

        // TRIANGLE_PERIMETER a b c
        else if (command == "TRIANGLE_PERIMETER") {
            double a, b, c;
            ss >> a >> b >> c;

            double per = Algebra::trianglePerimeter(a, b, c);
            cout << "TRIANGLE_PERIMETER = " << per << "\n";
            output << "TRIANGLE_PERIMETER = " << per << "\n";
        }

        // Unknown command
        else {
            cout << "Unknown command: " << command << "\n";
            output << "Unknown command: " << command << "\n";
        }
    }

    input.close();
    output.close();
    return 0;
}
