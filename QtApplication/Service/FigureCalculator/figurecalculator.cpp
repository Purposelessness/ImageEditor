#include "figurecalculator.h"

#include <cmath>

const double epsilon = 0.0000001;

FigurePoints FigureCalculator::calculateEllipse(int xLeft, int yTop, int xRight, int yBottom) {
    const int x_0 = (xLeft + xRight) / 2;
    const int y_0 = (yTop + yBottom) / 2;
    const int x_1 = xLeft - x_0;
    const int x_2 = xRight - x_0;
    const int y_1 = yTop - y_0;
    const int y_2 = yBottom - y_0;
    int a = x_2;
    int b = y_2;

    const int width = xRight - xLeft;
    const int height = yBottom - yTop;

    FigurePoints points = FigurePoints(xLeft, yTop, width, height);

    for (int x = x_1, xi = 0; x < x_2; ++x, ++xi) {
        for (int y = y_1, yi = 0; y < y_2; ++y, ++yi) {
            if (ellipseCheck(x, y, a, b)) {
                points.data[yi][xi] = true;
            }
        }
    }

    return points;
}

bool FigureCalculator::ellipseCheck(double x, double y, double a, double b) {
    double result = pow(x / a, 2) + pow(y / b, 2);
    return  (result - 1) < epsilon;
}
