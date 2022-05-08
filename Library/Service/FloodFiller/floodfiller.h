#ifndef IMAGEEDITOR_FLOODFILLER_H
#define IMAGEEDITOR_FLOODFILLER_H


#include "../../datastructures.h"

class FloodFiller {
public:
    static void start(FigurePoints *points, FillType fillType = FillType::fill, FillType borderType = FillType::border);
};


#endif //IMAGEEDITOR_FLOODFILLER_H
