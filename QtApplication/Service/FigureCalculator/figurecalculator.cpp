#include "figurecalculator.h"

#include "cmath"

FigurePoints FigureCalculator::calculateEllipse(int xLeft, int yTop, int xRight, int yBottom) {
    const int x_0 = (xLeft + xRight) / 2;
    const int y_0 = (yTop + yBottom) / 2;
    const int x_1 = xLeft - x_0;
    const int x_2 = xRight - x_0;
    const int y_1 = yTop - y_0;
    const int y_2 = yBottom - y_0;
    int a = x_2;
    int b = y_2;

    FigurePoints points = FigurePoints(xRight - xLeft, yBottom - yTop);

    for (int x = x_1, xi = 0; x < x_2; ++x, ++xi) {
        for (int y = y_1, yi = 0; y < y_2; ++y, ++yi) {
            if (ellipseCheck(x, y, x_0, y_0, a, b)) {
                points.data[xi][yi] = true;
            }
        }
    }

    return points;
}

bool FigureCalculator::ellipseCheck(double x, double y, double x_0, double y_0, double a, double b) {
    return (pow((x - x_0) / a, 2) + pow((y - y_0) / b, 2)) == 1;
}
