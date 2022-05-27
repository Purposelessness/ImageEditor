#ifndef IMAGEEDITOR_REFLECTOR_H
#define IMAGEEDITOR_REFLECTOR_H


#include "../../iimage.h"

enum class Orientation {
    horizontal,
    vertical
};

class Reflector {
public:
    static void start(IImage *image, const FigurePoints &points, Orientation orientation);

private:
    static void swap(Rgb *p1, Rgb *p2);
};


#endif //IMAGEEDITOR_REFLECTOR_H
