#ifndef IMAGEEDITOR_FIGURECALCULATOR_H
#define IMAGEEDITOR_FIGURECALCULATOR_H


#include "../../figurepoints.h"

class FigureCalculator {
public:
    static FigurePoints calculateEllipse(uint32_t xLeft, uint32_t yTop, uint32_t xRight, uint32_t yBottom, int borderWidth = 0);
};


#endif //IMAGEEDITOR_FIGURECALCULATOR_H
