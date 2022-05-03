#ifndef IMAGEEDITOR_ELLIPSECALCULATOR_H
#define IMAGEEDITOR_ELLIPSECALCULATOR_H


#include "../../figurepoints.h"

class EllipseCalculator {
public:
    static FigurePoints calculateEllipse(int xLeft, int yTop, int xRight, int yBottom, int borderWidth = 0);

private:
    static bool ellipseCheck(double x, double y, double a, double b);
};


#endif //IMAGEEDITOR_ELLIPSECALCULATOR_H
