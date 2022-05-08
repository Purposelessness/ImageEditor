#include "colorinverter.h"

#include <cstdio>

void ColorInverterData::start(IImage *image, const FigurePoints &points) {
    if (image->isEmpty()) {
        puts("Image is empty");
        return;
    }

    Rgb **data = image->getPixelData();
    int32_t imageWidth = image->getWidth();
    int32_t imageHeight = image->getHeight();
    int32_t width = points.width;
    int32_t height = points.height;

    for (int32_t y = 0; y < height; ++y) {
        for (int32_t x = 0; x < width; ++x) {
            if (points.data[y][x] != fill)
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

void ColorInverterData::start(IImage *image, const Point &point, IImage *srcImage, const FigurePoints &points) {
    if (image->isEmpty() || srcImage->isEmpty()) {
        puts("Image is empty");
        return;
    }

    Rgb **srcData = srcImage->getPixelData();
    Rgb **data = image->getPixelData();
    int32_t imageWidth = image->getWidth();
    int32_t imageHeight = image->getHeight();
    int32_t width = points.width;
    int32_t height = points.height;

    for (int32_t y = 0; y < height; ++y) {
        for (int32_t x = 0; x < width; ++x) {
            if (points.data[y][x] != fill)
                continue;

            int32_t xSrcImage = points.x + x;
            int32_t ySrcImage = points.y + y;
            int32_t xDestImage = point.x + x;
            int32_t yDestImage = point.y + y;

            if (!pointIsValid(xSrcImage, ySrcImage, imageWidth, imageHeight) ||
                !pointIsValid(xDestImage, yDestImage, imageWidth, imageHeight))
                continue;

            Rgb srcPixel = srcData[ySrcImage][xSrcImage];
            Rgb *pixel = &data[yDestImage][xDestImage];
            invertPixel(pixel, srcPixel);
        }
    }
}

void ColorInverterData::invertPixel(Rgb *pixel) {
    pixel->r = 255 - pixel->r;
    pixel->g = 255 - pixel->g;
    pixel->b = 255 - pixel->b;
}

void ColorInverterData::invertPixel(Rgb *pixel, Rgb srcPixel) {
    pixel->r = 255 - srcPixel.r;
    pixel->g = 255 - srcPixel.g;
    pixel->b = 255 - srcPixel.b;
}

bool ColorInverterData::pointIsValid(int32_t x, int32_t y, int32_t width, int32_t height) {
    return x >= 0 && x < width && y >= 0 && y < height;
}
