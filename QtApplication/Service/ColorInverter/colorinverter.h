#ifndef IMAGEEDITOR_COLORINVERTER_H
#define IMAGEEDITOR_COLORINVERTER_H


#include <cstddef>

struct PixelData {
    int x, y;
    int red, green, blue;
};

class ColorInverter {
public:
    static void invert(PixelData data[], size_t size);

private:
    static int invertColor(int value);
};


#endif //IMAGEEDITOR_COLORINVERTER_H
