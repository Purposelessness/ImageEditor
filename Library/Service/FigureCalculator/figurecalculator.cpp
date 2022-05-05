#include "figurecalculator.h"
#include "Type/ellipsecalculator.h"

FigurePoints FigureCalculator::calculateEllipse(int32_t xLeft, int32_t yTop, int32_t xRight, int32_t yBottom, int32_t borderWidth, bool fill) {
    if (!fill) {
        return Ellipse::calculateBresenham(xLeft, yTop, xRight, yBottom, borderWidth, fill);
    }
    return Ellipse::calculate(xLeft, yTop, xRight, yBottom, borderWidth, fill);
}

FigurePoints FigureCalculator::calculateEllipseBresenham(int32_t xLeft, int32_t yTop, int32_t xRight, int32_t yBottom, int32_t borderWidth, bool fill) {
    return Ellipse::calculateBresenham(xLeft, yTop, xRight, yBottom, borderWidth, fill);
}
