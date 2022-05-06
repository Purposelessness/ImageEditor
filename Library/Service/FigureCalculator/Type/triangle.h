#ifndef IMAGEEDITOR_TRIANGLE_H
#define IMAGEEDITOR_TRIANGLE_H


#include "../../../datastructures.h"

class Triangle {
public:
    static FigurePoints calculate(int32_t xLeft, int32_t yTop, int32_t xRight, int32_t yBottom, int32_t borderWidth = 0, bool fill = true);
};


#endif //IMAGEEDITOR_TRIANGLE_H
