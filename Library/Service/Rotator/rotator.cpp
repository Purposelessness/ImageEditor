#include "rotator.h"

#include <cstdio>
#include <cmath>

void Rotator::startBmp(Bitmap::Image *image, const Point &point, const FigurePoints &points, int angle) {
    if (image->isEmpty()) {
        puts("Image is empty");
        return;
    }

    auto srcImage = *image;
    Rgb **srcData = srcImage.getPixelData();
    Rgb **data = image->getPixelData();
    int32_t imageWidth = image->getWidth();
    int32_t imageHeight = image->getHeight();
    int32_t width = points.width;
    int32_t height = points.height;

    for (int32_t y = 0; y < height; ++y) {
        for (int32_t x = 0; x < width; ++x) {
            if (points.data[y][x] != FillType::fill)
                continue;

            int32_t xSrcImage = points.x + x;
            int32_t ySrcImage = points.y + y;
            int32_t cx = points.width / 2;
            int32_t cy = points.height / 2;
            int32_t tx = x - cx;
            int32_t ty = y - cy;
            Point dest = transformPixel({tx, ty}, angle);
            int32_t xDestImage = point.x + dest.x + cx;
            int32_t yDestImage = point.y + dest.y + cy;

            if (!pointIsValid(xSrcImage, ySrcImage, imageWidth, imageHeight) ||
                !pointIsValid(xDestImage, yDestImage, imageWidth, imageHeight))
                continue;

            Rgb srcPixel = srcData[ySrcImage][xSrcImage];
            Rgb *pixel = &data[yDestImage][xDestImage];
            pixel->r = srcPixel.r;
            pixel->g = srcPixel.g;
            pixel->b = srcPixel.b;
        }
    }
}

bool Rotator::pointIsValid(int32_t x, int32_t y, int32_t width, int32_t height) {
    return x >= 0 && x < width && y >= 0 && y < height;
}

Point Rotator::transformPixel(Point pixel, int angle) {
    double angled = angle * M_PI / 180;
    auto nx = static_cast<int32_t>(round(cos(angled) * pixel.x - sin(angled) * pixel.y));
    auto ny = static_cast<int32_t>(sin(angled) * pixel.x + cos(angled) * pixel.y);
    return {nx, ny, pixel.type};
}
