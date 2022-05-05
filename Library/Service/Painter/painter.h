#ifndef IMAGEEDITOR_PAINTER_H
#define IMAGEEDITOR_PAINTER_H


#include "../../iimage.h"

#include <vector>

class Painter {
public:
    static void start(IImage *image, const FigurePoints &points, const Rgb &fillColor, const Rgb &borderColor);
    static void start(IImage *image, const std::vector<Point> &points, const Rgb &fillColor, const Rgb &borderColor);

private:
    static bool pointIsValid(int32_t x, int32_t y, int32_t width, int32_t height);
};


#endif //IMAGEEDITOR_PAINTER_H
