#include "colorinverter.h"

void ColorInverter::invert(PixelData data[], int size) {
    for (int i = 0; i < size; ++i) {
        data[i].red = invertColor(data[i].red);
        data[i].green = invertColor(data[i].green);
        data[i].blue = invertColor(data[i].blue);
    }
}

int ColorInverter::invertColor(int value) {
    return 255 - value;
}
