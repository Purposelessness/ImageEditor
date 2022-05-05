#ifndef IMAGEEDITOR_FIGURECALCULATOR_H
#define IMAGEEDITOR_FIGURECALCULATOR_H


#include "../../figurepoints.h"

class FigureCalculator {
public:
    static FigurePoints calculateEllipse(int32_t xLeft, int32_t yTop, int32_t xRight, int32_t yBottom, int32_t borderWidth = 0, bool fill = true);
    static FigurePoints calculateEllipseBresenham(int32_t xLeft, int32_t yTop, int32_t xRight, int32_t yBottom, int32_t borderWidth = 0, bool fill = true);
};


#endif //IMAGEEDITOR_FIGURECALCULATOR_H
