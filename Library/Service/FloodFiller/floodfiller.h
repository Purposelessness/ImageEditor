#ifndef IMAGEEDITOR_FLOODFILLER_H
#define IMAGEEDITOR_FLOODFILLER_H


#include "../../datastructures.h"

class FloodFiller {
public:
    static void start(FigurePoints *points, Type fillType = fill, Type borderType = border);
};


#endif //IMAGEEDITOR_FLOODFILLER_H
