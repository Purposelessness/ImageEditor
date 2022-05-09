#include "ellipse.h"
#include "../constants.h"
#include "../../FloodFiller/floodfiller.h"

#include <cmath>
#include <cstdio>

FigurePoints Ellipse::calculate(int32_t xLeft, int32_t yTop, int32_t xRight, int32_t yBottom, int32_t borderWidth, bool fillFlag) {
    if (borderWidth == 0 && !fillFlag)
        return {0, 0, 0, 0};

    if (borderWidth == 1 || borderWidth == 0) {
        int32_t width = xRight - xLeft;
        int32_t height = yBottom - yTop;
        int32_t x0 = width / 2;
        int32_t y0 = height / 2;
        FigurePoints points{xLeft, yTop, width + 1, height + 1};

        FillType fillType = borderWidth == 1 ? FillType::border : FillType::fill;
        bresenhamEllipse(&points, x0, y0, x0, y0, fillType);
        FloodFiller::start(&points, FillType::fill, fillType);

        return points;
    }

    int32_t d = borderWidth / 2;

    int32_t xl = xLeft - d;
    int32_t yt = yTop - d;
    int32_t xr = xRight + d;
    int32_t yb = yBottom + d;
    int32_t width = xr - xl;
    int32_t height = yb - yt;
    FigurePoints points{xl, yt, width + 1, height + 1};

    int32_t x0 = width / 2;
    int32_t y0 = height / 2;
    int32_t rxo = x0;
    int32_t ryo = y0;
    int32_t rxi = x0 - borderWidth;
    int32_t ryi = y0 - borderWidth;

    bresenhamEllipse(&points, x0, y0, rxo, ryo);
    bresenhamEllipse(&points, x0, y0, rxi, ryi);

    FloodFiller::start(&points, FillType::border, FillType::border);
    if (fillFlag) FloodFiller::start(&points);

    return points;
}

void Ellipse::bresenhamEllipse(FigurePoints *figurePoints, int32_t cx, int32_t cy, int32_t xr, int32_t yr, FillType fillType) {
    int32_t twoASq = 2 * xr * xr;
    int32_t twoBSq = 2 * yr * yr;
    int32_t x = xr;
    int32_t y = 0;
    int32_t xCh = yr * yr * (1 - 2 * xr);
    int32_t yCh = xr * xr;
    int32_t err = 0;
    int32_t stopX = twoBSq * xr;
    int32_t stopY = 0;

    while (stopX >= stopY) {
        addPoints(figurePoints, cx, cy, x, y, fillType);
        ++y;
        stopY += twoASq;
        err += yCh;
        yCh += twoASq;
        if ((2 * err + xCh) > 0) {
            --x;
            stopX -= twoBSq;
            err += xCh;
            xCh += twoBSq;
        }
    }

    x = 0;
    y = yr;
    xCh = yr * yr;
    yCh = xr * xr * (1 - 2 * yr);
    err = 0;
    stopX = 0;
    stopY = twoASq * yr;
    while (stopX <= stopY) {
        addPoints(figurePoints, cx, cy, x, y, fillType);
        ++x;
        stopX += twoBSq;
        err += xCh;
        xCh += twoBSq;
        if ((2 * err + yCh) > 0) {
            --y;
            stopY -= twoASq;
            err += yCh;
            yCh += twoASq;
        }
    }
}

void Ellipse::addPoints(FigurePoints *points, int32_t cx, int32_t cy, int32_t x, int32_t y, FillType fillType) {
    points->data[cy + y][cx + x] = fillType;
    points->data[cy + y][cx - x] = fillType;
    points->data[cy - y][cx + x] = fillType;
    points->data[cy - y][cx - x] = fillType;
}

FigurePoints Ellipse::calculateEllipseEquation(int32_t xLeft, int32_t yTop, int32_t xRight, int32_t yBottom, int32_t borderWidth, bool fillFlag) {
    const int32_t x_0 = (xLeft + xRight) / 2;
    const int32_t y_0 = (yTop + yBottom) / 2;
    const int32_t x_1 = xLeft - x_0;
    const int32_t x_2 = xRight - x_0;
    const int32_t y_1 = yTop - y_0;
    const int32_t y_2 = yBottom - y_0;
    int32_t a = x_2, a_b = x_2 - borderWidth;
    int32_t b = y_2, b_b = y_2 - borderWidth;

    const int32_t width = xRight - xLeft + 1;
    const int32_t height = yBottom - yTop + 1;

    FigurePoints points = FigurePoints(xLeft, yTop, width, height);

    if (borderWidth == 0) {
        if (!fillFlag)
            return points;
        for (int32_t x = x_1, xi = 0; x < x_2; ++x, ++xi) {
            for (int32_t y = y_1, yi = 0; y < y_2; ++y, ++yi) {
                if (ellipseCheck(x, y, a, b)) {
                    points.data[yi][xi] = FillType::fill;
                }
            }
        }
    } else {
        for (int32_t x = x_1, xi = 0; x < x_2; ++x, ++xi) {
            for (int32_t y = y_1, yi = 0; y < y_2; ++y, ++yi) {
                if (!ellipseCheck(x, y, a, b))
                    continue;
                if (ellipseCheck(x, y, a_b, b_b)) {
                    if (fillFlag)
                        points.data[yi][xi] = FillType::fill;
                } else {
                    points.data[yi][xi] = FillType::border;
                }
            }
        }
    }

    return points;
}

bool Ellipse::ellipseCheck(double x, double y, double a, double b) {
    double result = pow(x / a, 2) + pow(y / b, 2);
    return (result - 1) < EPSILON;
}
