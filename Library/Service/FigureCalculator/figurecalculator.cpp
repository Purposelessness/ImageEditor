#include "figurecalculator.h"
#include "Type/ellipsecalculator.h"

FigurePoints FigureCalculator::calculateEllipse(uint32_t xLeft, uint32_t yTop, uint32_t xRight, uint32_t yBottom, int borderWidth) {
    return EllipseCalculator::calculateEllipse(xLeft, yTop, xRight, yBottom, borderWidth);
}
