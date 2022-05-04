#ifndef IMAGEEDITOR_COLORINVERTER_H
#define IMAGEEDITOR_COLORINVERTER_H


#include "../../iimage.h"

class ColorInverter {
public:
    static void start(IImage *image, const FigurePoints &points);

private:
    static void invertPixel(Rgb *pixel);
    static bool pointIsValid(int32_t x, int32_t y, int32_t width, int32_t height);
};


#endif //IMAGEEDITOR_COLORINVERTER_H
