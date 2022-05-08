#include <cstdio>
#include "painter.h"

void Painter::start(IImage *image, const FigurePoints &points, const Rgb &fillColor, const Rgb &borderColor) {
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
            if (points.data[y][x] != FillType::fill && points.data[y][x] != FillType::border)
                continue;

            int32_t xImage = points.x + x;
            int32_t yImage = points.y + y;
            if (!pointIsValid(xImage, yImage, imageWidth, imageHeight))
                continue;

            Rgb *pixel = &data[yImage][xImage];
            if (points.data[y][x] == FillType::fill) {
                pixel->r = fillColor.r;
                pixel->g = fillColor.g;
                pixel->b = fillColor.b;
            } else {
                pixel->r = borderColor.r;
                pixel->g = borderColor.g;
                pixel->b = borderColor.b;
            }
        }
    }
}

void Painter::start(IImage *image, const std::vector<Point> &points, const Rgb &fillColor, const Rgb &borderColor) {
    if (image->isEmpty()) {
        puts("Image is empty\n");
        return;
    }

    Rgb **data = image->getPixelData();
    int32_t imageWidth = image->getWidth();
    int32_t imageHeight = image->getHeight();
    size_t len = points.size();

    for (size_t i = 0; i < len; ++i) {
        auto point = points.at(i);
        if (point.type != FillType::fill && point.type != FillType::border)
            continue;

        int32_t xImage = point.x;
        int32_t yImage = point.y;
        if (!pointIsValid(xImage, yImage, imageWidth, imageHeight))
            continue;

        Rgb *pixel = &data[yImage][xImage];
        if (point.type == FillType::fill) {
            pixel->r = fillColor.r;
            pixel->g = fillColor.g;
            pixel->b = fillColor.b;
        } else {
            pixel->r = borderColor.r;
            pixel->g = borderColor.g;
            pixel->b = borderColor.b;
        }
    }
}

bool Painter::pointIsValid(int32_t x, int32_t y, int32_t width, int32_t height) {
    return x >= 0 && x < width && y >= 0 && y < height;
}
