#include "line.h"
#include "../../FloodFiller/floodfiller.h"

#include <cmath>

FigurePoints Line::calculate(int32_t x_0_r, int32_t y_0_r, int32_t x_1_r, int32_t y_1_r, int32_t borderWidth) {
    int32_t width = abs(x_1_r - x_0_r);
    int32_t height = abs(y_1_r - y_0_r);
    int32_t x0 = x_0_r < x_1_r ? x_0_r : x_1_r;
    int32_t x1 = x_0_r > x_1_r ? x_0_r : x_1_r;
    int32_t y0 = y_0_r < y_1_r ? y_0_r : y_1_r;
    int32_t y1 = y_0_r < y_1_r ? y_1_r : y_0_r;

    if (borderWidth == 1) {
        FigurePoints points{x0, y0, width + 1, height + 1};
        y_0_r < y_1_r ? bresenhamAlgorithm(&points, 0, width, 0, height)
                      : bresenhamAlgorithm(&points, 0, width, height, 0);
        return points;
    }

    auto d = borderWidth / 2.0;
    auto dint = static_cast<int32_t>(d);

    if (width == 0) {
        FigurePoints points{x0 - dint, y0, borderWidth, height + 1};
        for (int32_t x = 0; x < borderWidth; ++x) {
            for (int32_t y = 0; y < height; ++y) {
                points.data[y][x] = FillType::border;
            }
        }
        return points;
    } else if (height == 0) {
        FigurePoints points{x0, y0 - dint, width + 1, borderWidth};
        for (int32_t x = 0; x < width; ++x) {
            for (int32_t y = 0; y < borderWidth; ++y) {
                points.data[y][x] = FillType::border;
            }
        }
        return points;
    }

    auto a = static_cast<double>(width);
    auto b = static_cast<double>(height);
    double c = lineLength(x0, y0, x1, y1);
    double sinA = b / c;
    double cosA = a / c;
    auto dSinA = static_cast<int32_t>(round(d * sinA));
    auto dCosA = static_cast<int32_t>(round(d * cosA));

    int32_t xl, xr, yt, yb, x2, x3, y2, y3;
    xl = x0 - dSinA;
    xr = x1 + dSinA;
    yt = y0 - dCosA;
    yb = y1 + dCosA;
    width = xr - xl;
    height = yb - yt;
    FigurePoints points{xl, yt, width + 1, height + 1};

    x0 = 0;
    x1 = dSinA * 2;
    x2 = width;
    x3 = width - dSinA * 2;
    y0 = 2 * dCosA;
    y1 = 0;
    y2 = height - dCosA * 2;
    y3 = height;

    if (y_1_r > y_0_r) {
        bresenhamAlgorithm(&points, x0, x1, y0, y1);
        bresenhamAlgorithm(&points, x1, x2, y1, y2);
        bresenhamAlgorithm(&points, x2, x3, y2, y3);
        bresenhamAlgorithm(&points, x3, x0, y3, y0);
    } else {
        bresenhamAlgorithm(&points, x0, x1, y2, y3);
        bresenhamAlgorithm(&points, x1, x2, y3, y0);
        bresenhamAlgorithm(&points, x2, x3, y0, y1);
        bresenhamAlgorithm(&points, x3, x0, y1, y2);
    }

    FloodFiller::start(&points, FillType::border, FillType::border);

    return points;
}

void Line::bresenhamAlgorithm(FigurePoints *points, int32_t x_0, int32_t x_1, int32_t y_0, int32_t y_1, FillType fillType) {
    int32_t dx = x_1 - x_0;
    int32_t dy = y_1 - y_0;
    int32_t adx = abs(dx);
    int32_t ady = abs(dy);
    int32_t err = 0;
    int32_t sx = dx > 0 ? 1 : -1;
    int32_t sy = dy > 0 ? 1 : -1;
    if (adx > ady) {
        for (int32_t x = x_0, y = y_0; sx < 0 ? x >= x_1 : x <= x_1; x += sx) {
            points->data[y][x] = fillType;
            err += ady;
            if (err << 1 >= adx) {
                y += sy;
                err -= adx;
            }
        }
    } else {
        for (int x = x_0, y = y_0; sy < 0 ? y >= y_1 : y <= y_1; y += sy) {
            points->data[y][x] = fillType;
            err += adx;
            if (err << 1 >= ady) {
                x += sx;
                err -= ady;
            }
        }
    }
}

double Line::lineLength(int32_t x_0, int32_t y_0, int32_t x_1, int32_t y_1) {
    return sqrt(pow(x_1 - x_0, 2) + pow(y_1 - y_0, 2));
}
