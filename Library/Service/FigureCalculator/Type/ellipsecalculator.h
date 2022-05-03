#ifndef IMAGEEDITOR_ELLIPSECALCULATOR_H
#define IMAGEEDITOR_ELLIPSECALCULATOR_H


#include "../../../figurepoints.h"

class EllipseCalculator {
public:
    static FigurePoints calculateEllipse(uint32_t xLeft, uint32_t yTop, uint32_t xRight, uint32_t yBottom, int borderWidth = 0);

private:
    static bool ellipseCheck(double x, double y, double a, double b);
};


#endif //IMAGEEDITOR_ELLIPSECALCULATOR_H
