#ifndef IMAGEEDITOR_ROTATOR_H
#define IMAGEEDITOR_ROTATOR_H


#include "../../Bitmap/image.h"

struct TaskPoint {
    Point p;
    Point oldP;
};

class Rotator {
public:
    static void startBmp(Bitmap::Image *image, const Point &point, const FigurePoints &points, int angle);
    static void startBmpShear(Bitmap::Image *image, const Point &point, const FigurePoints &points, int angle);

private:
    static Point transformPixel(Point pixel, int angle);
    static Point transformPixelShearOne(Point pixel, int angle);
    static Point transformPixelShearTwo(Point pixel, int angle);
    static void transformPixelShearOne(Point &pixel, double tanHalf);
    static void transformPixelShearTwo(Point &pixel, double sinus);
    static bool pointIsValid(int32_t x, int32_t y, int32_t width, int32_t height);
};


#endif //IMAGEEDITOR_ROTATOR_H
