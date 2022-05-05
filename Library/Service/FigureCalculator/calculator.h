#ifndef IMAGEEDITOR_CALCULATOR_H
#define IMAGEEDITOR_CALCULATOR_H


#include "../../datastructures.h"

#include <vector>

class Calculator {
public:
    static FigurePoints calculateEllipse(int32_t xLeft, int32_t yTop, int32_t xRight, int32_t yBottom, int32_t borderWidth = 0, bool fill = true);
    static FigurePoints calculateEllipseBresenham(int32_t xLeft, int32_t yTop, int32_t xRight, int32_t yBottom, int32_t borderWidth = 0, bool fill = true);
    static FigurePoints calculateLine(int32_t x_0, int32_t y_0, int32_t x_1, int32_t y_1, int32_t borderWidth);
    static std::vector<Point> calculateLineV(int32_t x_0, int32_t y_0, int32_t x_1, int32_t y_1, int32_t borderWidth);
    static double lineLength(int32_t x_0, int32_t y_0, int32_t x_1, int32_t y_1);
};


#endif //IMAGEEDITOR_CALCULATOR_H
