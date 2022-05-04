#include "colorinverter.h"

#include <cstdio>

void ColorInverter::start(IImage *image, const FigurePoints &points) {
    if (image->isEmpty()) {
        puts("Image is empty\n");
        return;
    }

    Rgb **data = image->getPixelData();
    int32_t imageWidth = image->getWidth();
    int32_t imageHeight = image->getHeight();
    int32_t width = points.width;
    int32_t height = points.height;

    for (int32_t y = 0; y < height; ++y) {
        for (int32_t x = 0; x < width; ++x) {
            if (points.data[y][x] == none)
                continue;

            int32_t xImage = points.x + x;
            int32_t yImage = points.y + y;
            if (!pointIsValid(xImage, yImage, imageWidth, imageHeight))
                continue;

            Rgb *pixel = &data[yImage][xImage];
            invertPixel(pixel);
        }
    }
}

void ColorInverter::invertPixel(Rgb *pixel) {
    pixel->r = 255 - pixel->r;
    pixel->g = 255 - pixel->g;
    pixel->b = 255 - pixel->b;
}

bool ColorInverter::pointIsValid(int32_t x, int32_t y, int32_t width, int32_t height) {
    return x >= 0 && x < width && y >= 0 && y < height;
}
