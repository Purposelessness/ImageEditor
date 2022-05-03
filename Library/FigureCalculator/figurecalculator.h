#ifndef IMAGEEDITOR_FIGURECALCULATOR_H
#define IMAGEEDITOR_FIGURECALCULATOR_H


#include "../figurepoints.h"

class FigureCalculator {
public:
    static FigurePoints calculateEllipse(int xLeft, int yTop, int xRight, int yBottom, int borderWidth = 0);
};


#endif //IMAGEEDITOR_FIGURECALCULATOR_H
