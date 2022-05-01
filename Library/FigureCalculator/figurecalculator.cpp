#include "figurecalculator.h"
#include "Type/ellipsecalculator.h"

FigurePoints FigureCalculator::calculateEllipse(int xLeft, int yTop, int xRight, int yBottom, int borderWidth) {
    return EllipseCalculator::calculateEllipse(xLeft, yTop, xRight, yBottom, borderWidth);
}
