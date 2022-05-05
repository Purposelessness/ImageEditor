#ifndef IMAGEEDITOR_DATASTRUCTURES_H
#define IMAGEEDITOR_DATASTRUCTURES_H


#include "figurepoints.h"

#pragma pack(push, 1)
struct Rgb {
    uint8_t b;
    uint8_t g;
    uint8_t r;
    [[nodiscard]] bool isValid() const {
        return r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255;
    }
};
#pragma pack(pop)


#endif //IMAGEEDITOR_DATASTRUCTURES_H
