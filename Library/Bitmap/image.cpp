#include "image.h"

#include <cstdio>

namespace Bitmap {

    Image::Image(const Bitmap::FileHeader &fileHeader, const Bitmap::InfoHeader &infoHeader,
                 Rgb **pixelData) :
            fileHeader(fileHeader), infoHeader(infoHeader), pixelData(pixelData) {}

    Image::~Image() {
        delete[] pixelData;
    }

    bool Image::isEmpty() const {
        return pixelData == nullptr;
    }

    Rgb **Image::getPixelData() {
        return pixelData;
    }

    FileHeader *Image::getFileHeader() {
        return &fileHeader;
    }

    InfoHeader *Image::getInfoHeader() {
        return &infoHeader;
    }

    int32_t Image::getHeight() const {
        return infoHeader.getHeight();
    }

    int32_t Image::getWidth() const {
        return infoHeader.getWidth();
    }

    void Image::setHeight(int32_t height) {
        infoHeader.setHeight(height);
    }

    void Image::setWidth(int32_t width) {
        infoHeader.setWidth(width);
    }

}