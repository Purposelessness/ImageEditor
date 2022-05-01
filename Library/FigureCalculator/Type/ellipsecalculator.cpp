#include "ellipsecalculator.h"
#include "../constants.h"

#include <cmath>

FigurePoints EllipseCalculator::calculateEllipse(int xLeft, int yTop, int xRight, int yBottom, int borderWidth) {
    const int x_0 = (xLeft + xRight) / 2;
    const int y_0 = (yTop + yBottom) / 2;
    const int x_1 = xLeft - x_0;
    const int x_2 = xRight - x_0;
    const int y_1 = yTop - y_0;
    const int y_2 = yBottom - y_0;
    int a = x_2, a_b = x_2 - borderWidth;
    int b = y_2, b_b = y_2 - borderWidth;

    const int width = xRight - xLeft;
    const int height = yBottom - yTop;

    FigurePoints points = FigurePoints(xLeft, yTop, width, height);

    if (borderWidth == 0) {
        for (int x = x_1, xi = 0; x < x_2; ++x, ++xi) {
            for (int y = y_1, yi = 0; y < y_2; ++y, ++yi) {
                if (ellipseCheck(x, y, a, b)) {
                    points.data[yi][xi] = fill;
                }
            }
        }
    } else {
        for (int x = x_1, xi = 0; x < x_2; ++x, ++xi) {
            for (int y = y_1, yi = 0; y < y_2; ++y, ++yi) {
                if (ellipseCheck(x, y, a, b)) {
                    if (ellipseCheck(x, y, a_b, b_b)) {
                        points.data[yi][xi] = fill;
                    } else {
                        points.data[yi][xi] = border;
                    }
                }
            }
        }
    }

    return points;
}

bool EllipseCalculator::ellipseCheck(double x, double y, double a, double b) {
    double result = pow(x / a, 2) + pow(y / b, 2);
    return (result - 1) < EPSILON;
}
