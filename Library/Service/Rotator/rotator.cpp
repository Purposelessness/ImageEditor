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

    int32_t cx = points.width / 2;
    int32_t cy = points.height / 2;

    for (int32_t y = 0; y < height; ++y) {
        for (int32_t x = 0; x < width; ++x) {
            if (points.data[y][x] != FillType::fill)
                continue;

            int32_t xSrcImage = points.x + x;
            int32_t ySrcImage = points.y + y;
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
            *pixel = srcPixel;
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

void Rotator::startBmpShear(Bitmap::Image *image, const Point &point, const FigurePoints &points, int angle) {
    if (image->isEmpty()) {
        puts("Image is empty");
        return;
    }

    angle %= 360;
    if (angle < 0) angle += 360;

    Bitmap::Image srcImage = *image;
    Rgb **srcData = srcImage.getPixelData();
    Rgb **data = image->getPixelData();
    int32_t imageWidth = image->getWidth();
    int32_t imageHeight = image->getHeight();
    int32_t width = points.width;
    int32_t height = points.height;

    int32_t cx = points.width / 2;
    int32_t cy = points.height / 2;

    for (int32_t y = 0; y < height; ++y) {
        for (int32_t x = 0; x < width; ++x) {
            if (points.data[y][x] != FillType::fill)
                continue;
            int32_t ox = points.x + x;
            int32_t oy = points.y + y;

            Point p{x - cx, y - cy};
            shear(p, angle);

            int32_t destX = point.x + cx + p.x;
            int32_t destY = point.y + cy + p.y;

            if (!pointIsValid(destX, destY, imageWidth, imageHeight) ||
                !pointIsValid(ox, oy, imageWidth, imageHeight))
                continue;

            Rgb srcPixel = srcData[oy][ox];
            Rgb *pixel = &data[destY][destX];
            *pixel = srcPixel;
        }
    }
}

void Rotator::shear(Point &pixel, int angle) {
    auto ang = angle * M_PI / 180;
    auto tangent = tan(ang / 2);

    auto nx = round(pixel.x - pixel.y * tangent);
    auto ny = static_cast<double>(pixel.y);

    ny = round(nx * sin(ang) + ny);

    nx = round(nx - ny * tangent);

    pixel.x = static_cast<int32_t>(nx);
    pixel.y = static_cast<int32_t>(ny);
}
