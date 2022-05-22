#include "rotator.h"

#include <cstdio>
#include <cmath>
#include <vector>

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

void Rotator::startBmpShear(Bitmap::Image *image, const Point &point, const FigurePoints &points, int angle) {
    if (image->isEmpty()) {
        puts("Image is empty");
        return;
    }

    Bitmap::Image srcImage = *image;
    Rgb **srcData = srcImage.getPixelData();
    Rgb **data = image->getPixelData();
    int32_t imageWidth = image->getWidth();
    int32_t imageHeight = image->getHeight();
    int32_t width = points.width;
    int32_t height = points.height;

    std::vector<TaskPoint> pVector;

    int32_t cx = points.width / 2;
    int32_t cy = points.height / 2;

    double angled = angle * M_PI / 180;
    auto sinus = sin(angled);
    auto tanHalf = tan(angled / 2);

    for (int32_t y = 0; y < height; ++y) {
        for (int32_t x = 0; x < width; ++x) {
            if (points.data[y][x] != FillType::fill)
                continue;
            pVector.push_back({{x - cx, y - cy}, {points.x + x, points.y + y}});
        }
    }
    for (auto &i : pVector) {
        transformPixelShearOne(i.p, tanHalf);
    }
    for (auto &i : pVector) {
        transformPixelShearTwo(i.p, sinus);
    }
    for (auto &i : pVector) {
        transformPixelShearOne(i.p, tanHalf);
    }

    for (auto i : pVector) {
        int32_t x = point.x + cx + i.p.x;
        int32_t y = point.y + cy + i.p.y;
        int32_t srcX = i.oldP.x;
        int32_t srcY = i.oldP.y;

        if (!pointIsValid(srcX, srcY, imageWidth, imageHeight) ||
            !pointIsValid(x, y, imageWidth, imageHeight))
            continue;

        Rgb srcPixel = srcData[srcY][srcX];
        Rgb *pixel = &data[y][x];
        pixel->r = srcPixel.r;
        pixel->g = srcPixel.g;
        pixel->b = srcPixel.b;
    }
}

Point Rotator::transformPixelShearOne(Point pixel, int angle) {
    double angled = angle * M_PI / 180;
    auto tanHalf = tan(angled / 2);
    auto nx = static_cast<int32_t>(round(pixel.x - pixel.y * tanHalf));
    return {nx, pixel.y, pixel.type};
}

Point Rotator::transformPixelShearTwo(Point pixel, int angle) {
    double angled = angle * M_PI / 180;
    auto sinus = sin(angled);
    auto ny = static_cast<int32_t>(round(sinus * pixel.x + pixel.y));
    return {pixel.x, ny, pixel.type};
}

void Rotator::transformPixelShearOne(Point &pixel, double tanHalf) {
    auto nx = static_cast<int32_t>(round(pixel.x - pixel.y * tanHalf));
    pixel.x = nx;
}

void Rotator::transformPixelShearTwo(Point &pixel, double sinus) {
    auto ny = static_cast<int32_t>(round(sinus * pixel.x + pixel.y));
    pixel.y = ny;
}
