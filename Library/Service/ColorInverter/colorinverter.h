#ifndef IMAGEEDITOR_COLORINVERTER_H
#define IMAGEEDITOR_COLORINVERTER_H


#include "../../iimage.h"

class ColorInverter {
public:
    static void start(IImage *image, const FigurePoints &points);

private:
    static void invertPixel(Rgb *pixel);
    static bool pointIsValid(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
};


#endif //IMAGEEDITOR_COLORINVERTER_H
