#ifndef IMAGEEDITOR_DATASTRUCTURES_H
#define IMAGEEDITOR_DATASTRUCTURES_H


#include <cstdint>
#include "figurepoints.h"

#pragma pack(push, 1)
struct Rgb {
    uint8_t b;
    uint8_t g;
    uint8_t r;
};
#pragma pack(pop)


#endif //IMAGEEDITOR_DATASTRUCTURES_H
