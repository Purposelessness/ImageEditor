#ifndef IMAGEEDITOR_IIMAGE_H
#define IMAGEEDITOR_IIMAGE_H


#include "datastructures.h"

class IImage {
public:
    [[nodiscard]] virtual bool isEmpty() const = 0;

    virtual void setHeight(int32_t height) = 0;
    virtual void setWidth(int32_t width) = 0;

    virtual Rgb **getPixelData() = 0;
    [[nodiscard]] virtual int32_t getHeight() const = 0;
    [[nodiscard]] virtual int32_t getWidth() const = 0;
    [[nodiscard]] virtual Rect getCropRect() const = 0;
};


#endif //IMAGEEDITOR_IIMAGE_H
