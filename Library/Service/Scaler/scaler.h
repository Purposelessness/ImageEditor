#ifndef IMAGEEDITOR_SCALER_H
#define IMAGEEDITOR_SCALER_H


#include "../../Bitmap/image.h"

class Scaler {
public:
    static Bitmap::Image startBmp(Bitmap::Image &image, int32_t newWidth, int32_t newHeight, const FigurePoints &points = FigurePoints());
    static FigurePoints startPoints(const FigurePoints &figurePoints, int32_t newWidth, int32_t newHeight);
    static Point startPoint(const Point &point, double scale);
};


#endif //IMAGEEDITOR_SCALER_H
