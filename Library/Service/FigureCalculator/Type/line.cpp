#include "line.h"

#include <cmath>
#include <cstdio>

FigurePoints Line::calculate(int32_t x_0_r, int32_t y_0_r, int32_t x_1_r, int32_t y_1_r, int32_t borderWidth) {
    int32_t width = abs(x_1_r - x_0_r);
    int32_t height = abs(y_1_r - y_0_r);
    int32_t x0 = x_0_r < x_1_r ? x_0_r : x_1_r;
    int32_t x1 = x_0_r > x_1_r ? x_0_r : x_1_r;
    int32_t y0 = y_0_r < y_1_r ? y_0_r : y_1_r;
    int32_t y1 = y_0_r > y_1_r ? y_0_r : y_1_r;

    if (borderWidth == 1) {
        FigurePoints points{x0, y0, width + 1, height + 1};
        y_0_r < y_1_r ? bresenhamAlgorithm(&points, 0, width, 0, height)
                      : bresenhamAlgorithm(&points, 0, width, height, 0);
        return points;
    }

    auto d = borderWidth / 2.0;
    int r = borderWidth % 2;
    auto dint = static_cast<int32_t>(d);

    if (width == 0) {
        FigurePoints points{x0 - dint, y0, borderWidth, height + 1};
        for (int32_t x = 0; x < borderWidth; ++x) {
            for (int32_t y = 0; y < height; ++y) {
                points.data[y][x] = border;
            }
        }
        return points;
    } else if (height == 0) {
        FigurePoints points{x0, y0 - dint, width + 1, borderWidth};
        for (int32_t x = 0; x < width; ++x) {
            for (int32_t y = 0; y < borderWidth; ++y) {
                points.data[y][x] = border;
            }
        }
        return points;
    }

    auto a = static_cast<double>(width);
    auto b = static_cast<double>(height);
    auto c = lineLength(x_0_r, y_0_r, x_1_r, y_1_r);
    auto sinA = b / c;
    auto cosA = a / c;
    auto xShift = static_cast<int32_t>(d * sinA);
    auto yShift = static_cast<int32_t>(d * cosA);

    return {0, 0, 0, 0};
}

void Line::bresenhamAlgorithm(FigurePoints *points, int32_t x_0, int32_t x_1, int32_t y_0, int32_t y_1) {
    int32_t dx = x_1 - x_0;
    int32_t dy = y_1 - y_0;
    int32_t adx = abs(dx);
    int32_t ady = abs(dy);
    int32_t err = 0;
    int32_t sx = dx > 0 ? 1 : -1;
    int32_t sy = dy > 0 ? 1 : -1;
    if (adx > ady) {
        for (int32_t x = x_0, y = y_0; sx < 0 ? x >= x_1 : x <= x_1; x += sx) {
            points->data[y][x] = border;
            err += ady;
            if (err << 1 >= adx) {
                y += sy;
                err -= adx;
            }
        }
    } else {
        for (int x = x_0, y = y_0; sy < 0 ? y >= y_1 : y <= y_1; y += sy) {
            points->data[y][x] = border;
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
