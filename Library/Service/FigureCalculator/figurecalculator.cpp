#include "figurecalculator.h"
#include "Type/ellipsecalculator.h"

FigurePoints FigureCalculator::calculateEllipse(int32_t xLeft, int32_t yTop, int32_t xRight, int32_t yBottom, int32_t borderWidth) {
    return EllipseCalculator::calculateEllipse(xLeft, yTop, xRight, yBottom, borderWidth);
}

FigurePoints FigureCalculator::calculateEllipseBresenham(int32_t xLeft, int32_t yTop, int32_t xRight, int32_t yBottom, int32_t borderWidth) {
    return EllipseCalculator::calculateEllipseBresenham(xLeft, yTop, xRight, yBottom, borderWidth);
}
