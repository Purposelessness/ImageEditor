#ifndef IMAGEEDITOR_IIMAGE_H
#define IMAGEEDITOR_IIMAGE_H


#include "datastructures.h"

class IImage {
public:
    [[nodiscard]] virtual bool isEmpty() const = 0;

    virtual void setHeight(uint32_t height) = 0;
    virtual void setWidth(uint32_t width) = 0;

    virtual Rgb **getPixelData() = 0;
    [[nodiscard]] virtual uint32_t getHeight() const = 0;
    [[nodiscard]] virtual uint32_t getWidth() const = 0;
};


#endif //IMAGEEDITOR_IIMAGE_H
