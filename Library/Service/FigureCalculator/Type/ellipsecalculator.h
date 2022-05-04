#ifndef IMAGEEDITOR_ELLIPSECALCULATOR_H
#define IMAGEEDITOR_ELLIPSECALCULATOR_H


#include "../../../figurepoints.h"

class EllipseCalculator {
public:
    static FigurePoints calculateEllipse(int32_t xLeft, int32_t yTop, int32_t xRight, int32_t yBottom, int32_t borderWidth = 0);
    static FigurePoints calculateEllipseBresenham(int32_t xLeft, int32_t yTop, int32_t xRight, int32_t yBottom, int32_t borderWidth = 0);

private:
    static bool ellipseCheck(double x, double y, double a, double b);
    static void bresenhamEllipse(FigurePoints *points, int32_t cx, int32_t cy, int32_t xr, int32_t yr, type fillType = fill);
    static void addPoints(FigurePoints *points, int32_t cx, int32_t cy, int32_t x, int32_t y, type fillType);
};


#endif //IMAGEEDITOR_ELLIPSECALCULATOR_H
