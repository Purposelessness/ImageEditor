#ifndef IMAGEEDITOR_DATASTRUCTURES_H
#define IMAGEEDITOR_DATASTRUCTURES_H


#include "figurepoints.h"

#pragma pack(push, 1)
struct Rgb {
    uint8_t b = 0;
    uint8_t g = 0;
    uint8_t r = 0;
};
#pragma pack(pop)

struct PixelData {
    Rgb **rgb{};
    int32_t width{};
    int32_t height{};
};

struct Point {
    int32_t x{}, y{};
    FillType type{};
};

struct Rect {
    int32_t x{}, y{};
    int32_t width{}, height{};

    [[nodiscard]] bool isNull() const {
        return width == 0 && height == 0;
    }
};


#endif //IMAGEEDITOR_DATASTRUCTURES_H
