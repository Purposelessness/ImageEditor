#include <cstdio>
#include "painter.h"

void Painter::start(IImage *image, const FigurePoints &points, const Rgb &fillColor, const Rgb &borderColor) {
    if (image->isEmpty()) {
        puts("Image is empty\n");
        return;
    }

    if (points.isNull())
        return;

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

    if (points.empty())
        return;

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

void Painter::drawRect(IImage *image, int32_t width, const Point &point, const Rgb &color, const Rgb &e, bool eFlag) {
    auto pixelData = image->getPixelData();
    drawRect({pixelData, image->getWidth(), image->getHeight()}, width, point, color, e, eFlag);
}

void Painter::drawRect(const PixelData &pixelData, int32_t width, const Point &point, const Rgb &color, const Rgb &e, bool eFlag) {
    auto rgb = pixelData.rgb;
    auto pw = pixelData.width;
    auto ph = pixelData.height;
    auto cx = point.x;
    auto cy = point.y;
    if (width == 1) {
        if (pointIsValid(cx, cy, pw, ph))
            rgb[cy][cx] = color;
        return;
    }

    int32_t a = width / 2;
    if (eFlag) {
        for (int32_t y = cy - a; y <= cy + a; ++y) {
            for (int32_t x = cx - a; x <= cx + a; ++x) {
                auto pix = &rgb[y][x];
                if (pointIsValid(x, y, pw, ph) && !rgbEqual(*pix, e))
                    *pix = color;
            }
        }
    } else {
        for (int32_t y = cy - a; y <= cy + a; ++y) {
            for (int32_t x = cx - a; x <= cx + a; ++x) {
                if (pointIsValid(x, y, pw, ph))
                    rgb[y][x] = color;
            }
        }
    }
}

bool Painter::pointIsValid(int32_t x, int32_t y, int32_t width, int32_t height) {
    return x >= 0 && x < width && y >= 0 && y < height;
}
