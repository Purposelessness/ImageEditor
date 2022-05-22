#include "image.h"

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

    Image::Image(const Image &other) {
        fileHeader = other.fileHeader;
        infoHeader = other.infoHeader;
        int32_t width = other.getWidth();
        int32_t height = other.getHeight();
        pixelData = new Rgb *[height];
        for (int32_t y = 0; y < height; ++y) {
            pixelData[y] = new Rgb[width];
            for (int32_t x = 0; x < width; ++x) {
                pixelData[y][x] = other.pixelData[y][x];
            }
        }
    }

    void Image::setCropRect(const Rect &newCropRect) {
        cropRect = newCropRect;
    }

    Rect Image::getCropRect() const {
        return cropRect;
    }

    bool Image::isPixelValid(int32_t x, int32_t y) const {
        return x >= 0 && x < infoHeader.getWidth() && y >= 0 && y < infoHeader.getHeight();
    }

}