#ifndef IMAGEEDITOR_SCALER_H
#define IMAGEEDITOR_SCALER_H


#include "../../Bitmap/image.h"

class Scaler {
public:
    static Bitmap::Image startBmp(Bitmap::Image &image, int32_t newWidth, int32_t newHeight, const FigurePoints &points = FigurePoints());

private:
    static Rgb getPixel();
};


#endif //IMAGEEDITOR_SCALER_H
