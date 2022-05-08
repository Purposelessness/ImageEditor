#ifndef IMAGEEDITOR_ELLIPSE_H
#define IMAGEEDITOR_ELLIPSE_H


#include "../../../figurepoints.h"

class Ellipse {
public:
    static FigurePoints calculate(int32_t xLeft, int32_t yTop, int32_t xRight, int32_t yBottom, int32_t borderWidth = 0, bool fill = true);
    static FigurePoints calculateBresenham(int32_t xLeft, int32_t yTop, int32_t xRight, int32_t yBottom, int32_t borderWidth = 0, bool fill = false);

private:
    static bool ellipseCheck(double x, double y, double a, double b);
    static void bresenhamEllipse(FigurePoints *points, int32_t cx, int32_t cy, int32_t xr, int32_t yr, FillType fillType = FillType::fill);
    static void addPoints(FigurePoints *points, int32_t cx, int32_t cy, int32_t x, int32_t y, FillType fillType);
};


#endif //IMAGEEDITOR_ELLIPSE_H
