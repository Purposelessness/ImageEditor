#ifndef IMAGEEDITOR_GLUE_H
#define IMAGEEDITOR_GLUE_H


#include "../../Bitmap/image.h"

class Glue {
public:
    static void start(Bitmap::Image *image1, Bitmap::Image *image2);

private:
    static int32_t max(int32_t a, int32_t b);
};


#endif //IMAGEEDITOR_GLUE_H
