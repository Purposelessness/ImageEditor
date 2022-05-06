#include "calculator.h"
#include "Type/ellipse.h"
#include "Type/line.h"
#include "Type/triangle.h"

FigurePoints Calculator::ellipse(int32_t xLeft, int32_t yTop, int32_t xRight, int32_t yBottom, int32_t borderWidth, bool fill) {
    if (!fill) {
        return Ellipse::calculateBresenham(xLeft, yTop, xRight, yBottom, borderWidth, fill);
    }
    return Ellipse::calculate(xLeft, yTop, xRight, yBottom, borderWidth, fill);
}

FigurePoints Calculator::ellipseBresenham(int32_t xLeft, int32_t yTop, int32_t xRight, int32_t yBottom, int32_t borderWidth, bool fill) {
    return Ellipse::calculateBresenham(xLeft, yTop, xRight, yBottom, borderWidth, fill);
}

FigurePoints Calculator::triangle(int32_t xLeft, int32_t yTop, int32_t xRight, int32_t yBottom, int32_t borderWidth, bool fill) {
    return Triangle::calculate(xLeft, yTop, xRight, yBottom, borderWidth, fill);
}

FigurePoints Calculator::line(int32_t x_0, int32_t y_0, int32_t x_1, int32_t y_1, int32_t borderWidth) {
    return borderWidth == 0 ? FigurePoints{0, 0, 0, 0} : Line::calculate(x_0, y_0, x_1, y_1, borderWidth);
}

double Calculator::lineLength(int32_t x_0, int32_t y_0, int32_t x_1, int32_t y_1) {
    return Line::lineLength(x_0, y_0, x_1, y_1);
}
