#include "floodfiller.h"

void FloodFiller::start(FigurePoints *points, Type fillType, Type borderType) {
    const int32_t width = points->width;
    const int32_t height = points->height;

    for (int32_t y = 0; y < height; ++y) {
        int32_t x, x1, x2;
        for (x = 0; x < width && points->data[y][x] != borderType; points->data[y][x] = none, ++x) {}
        x1 = x;
        for (x = width - 1; x > x1 && points->data[y][x] != borderType; points->data[y][x] = none, --x);
        for (; x > x1 && points->data[y][x] == borderType; --x);
        if (points->data[y][x] != unknown)
            continue;
        for (; x > x1 && points->data[y][x] == unknown; points->data[y][x] = fillType, --x);
        x2 = x;
        for (x = x1 + 1; x < x2 && points->data[y][x] == borderType; ++x);
        if (points->data[y][x] != unknown)
            continue;
        for (; x < x2 && points->data[y][x] == unknown; points->data[y][x] = fillType, ++x);
    }
}
