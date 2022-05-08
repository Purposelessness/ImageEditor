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

struct Point {
    int32_t x, y;
    Type type;
};


#endif //IMAGEEDITOR_DATASTRUCTURES_H
