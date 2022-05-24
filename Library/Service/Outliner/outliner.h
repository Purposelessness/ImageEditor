#ifndef IMAGEEDITOR_OUTLINER_H
#define IMAGEEDITOR_OUTLINER_H


#include "../../iimage.h"

class Outliner {
public:
    static void start(IImage *image, const Rgb &color, const Rgb &outlineColor, int32_t thickness);

private:
    static bool rgbEqual(const Rgb &r1, const Rgb &r2);
};


#endif //IMAGEEDITOR_OUTLINER_H
