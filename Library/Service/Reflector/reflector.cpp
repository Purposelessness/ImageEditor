#include <cstdio>
#include "reflector.h"

void Reflector::start(IImage *image, const FigurePoints &points, Orientation orientation) {
    auto data = image->getPixelData();
    auto iw = image->getWidth();
    auto ih = image->getHeight();
    auto sx = points.x;
    auto sy = points.y;
    auto ex = sx + points.width;
    auto ey = sy + points.height;
    if (sx >= iw || sy >= ih || ex <= 0 || ey <= 0) {
        return;
    }

    if (sx < 0) sx = 0;
    if (sy < 0) sy = 0;
    if (ex > iw) ex = iw;
    if (ey > ih) ey = ih;

    auto w = ex - sx;
    auto h = ey - sy;
    auto halfW = w / 2;
    auto halfH = h / 2;

    if (w == 0 || h == 0) {
        return;
    }

    printf("%d %d %d %d\n", w, h, halfW, halfH);

    switch (orientation) {
        case Orientation::vertical:
            for (int32_t y = 0; y < halfH; ++y) {
                for (int32_t x = 0; x < w; ++x) {
                    swap(&data[sy + y][sx + x], &data[sy + 2 * halfH - y][sx + x]);
                }
            }
            break;
        case Orientation::horizontal:
            for (int32_t y = 0; y < h; ++y) {
                for (int32_t x = 0; x < halfW; ++x) {
                    swap(&data[sy + y][sx + x], &data[sy + y][sx + 2 * halfW - x]);
                }
            }
            break;
    }
}

void Reflector::swap(Rgb *p1, Rgb *p2) {
    auto pt = *p1;
    *p1 = *p2;
    *p2 = pt;
}
