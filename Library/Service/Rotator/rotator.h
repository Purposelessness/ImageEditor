#ifndef IMAGEEDITOR_ROTATOR_H
#define IMAGEEDITOR_ROTATOR_H


#include "../../iimage.h"

class Rotator {
public:
    static void start(IImage *image, const Point &point, IImage *srcImage, const FigurePoints &points, int angle);

private:
    static Point transformPixel(Point pixel, int angle);
    static bool pointIsValid(int32_t x, int32_t y, int32_t width, int32_t height);
};


#endif //IMAGEEDITOR_ROTATOR_H
