#include "colorinverter.h"

#include <cstdio>

void ColorInverter::start(IImage *image, const FigurePoints &points) {
    if (image->isEmpty()) {
        puts("Image is empty\n");
        return;
    }

    Rgb **data = image->getPixelData();
    uint32_t imageWidth = image->getWidth();
    uint32_t imageHeight = image->getHeight();
    uint32_t width = points.width;
    uint32_t height = points.height;

    for (uint32_t y = 0; y < height; ++y) {
        for (uint32_t x = 0; x < width; ++x) {
            if (points.data[y][x] == none)
                continue;

            uint32_t xImage = points.x + x;
            uint32_t yImage = points.y + y;
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

bool ColorInverter::pointIsValid(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
    return x >= 0 && x < width && y >= 0 && y < height;
}
