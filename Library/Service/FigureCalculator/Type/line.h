#ifndef IMAGEEDITOR_LINE_H
#define IMAGEEDITOR_LINE_H


#include "../../../datastructures.h"

#include <vector>

class Line {
public:
    static FigurePoints calculate(int32_t x_0, int32_t y_0, int32_t x_1, int32_t y_1, int32_t borderWidth = 0);
    static double lineLength(int32_t x_0, int32_t y_0, int32_t x_1, int32_t y_1);
    static void bresenhamAlgorithm(FigurePoints *points, int32_t x_0, int32_t x_1, int32_t y_0, int32_t y_1, FillType fillType = FillType::border);
};


#endif //IMAGEEDITOR_LINE_H
