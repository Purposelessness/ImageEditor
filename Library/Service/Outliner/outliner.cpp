#include "outliner.h"
#include "../Painter/painter.h"

void Outliner::start(IImage *image, const Rgb &color, const Rgb &outlineColor, const int32_t thickness) {
    auto width = image->getWidth();
    auto height = image->getHeight();
    auto rgb = image->getPixelData();
    for (int32_t y = 0; y < height; ++y) {
        for (int32_t x = 0; x < width; ++x) {
            if (rgbEqual(rgb[y][x], color))
                Painter::drawRect({rgb, width, height}, thickness, {x, y}, outlineColor, color, true);
        }
    }
}


