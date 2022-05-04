#include "image.h"

#include <cstdio>

namespace Bitmap {

    Image::Image(const Bitmap::FileHeader &fileHeader, const Bitmap::V3Header &infoHeader,
                 Rgb **pixelData) :
            fileHeader(fileHeader), infoHeader(infoHeader), pixelData(pixelData) {}

    Image::~Image() {
        delete[] pixelData;
    }

    bool Image::isEmpty() const {
        return pixelData == nullptr;
    }

    void Image::printFileHeader() const {
        printf("Signature:          \t%x (%hu)\n", fileHeader.type, fileHeader.type);
        printf("FileSize:           \t%x (%u)\n", fileHeader.fileSize, fileHeader.fileSize);
        printf("Reserved1:          \t%x (%hu)\n", fileHeader.reserved1, fileHeader.reserved1);
        printf("Reserved2:          \t%x (%hu)\n", fileHeader.reserved2, fileHeader.reserved2);
        printf("PixelArrayOffset:   \t%x (%u)\n", fileHeader.pixelArrayOffset, fileHeader.pixelArrayOffset);
    }

    void Image::printInfoHeader() const {
        printf("HeaderSize:         \t%x (%u)\n", infoHeader.size, infoHeader.size);
        printf("Width:              \t%x (%u)\n", infoHeader.width, infoHeader.width);
        printf("Height:             \t%x (%u)\n", infoHeader.height, infoHeader.height);
        printf("Planes:             \t%x (%hu)\n", infoHeader.planes, infoHeader.planes);
        printf("BitsPerPixel:       \t%x (%hu)\n", infoHeader.bitsPerPixel, infoHeader.bitsPerPixel);
        printf("Compression:        \t%x (%u)\n", infoHeader.compression, infoHeader.compression);
        printf("ImageSize:          \t%x (%u)\n", infoHeader.imageSize, infoHeader.imageSize);
        printf("XPixelsPerMeter:    \t%x (%u)\n", infoHeader.xPixelsPerMeter, infoHeader.xPixelsPerMeter);
        printf("YPixelsPerMeter:    \t%x (%u)\n", infoHeader.yPixelsPerMeter, infoHeader.yPixelsPerMeter);
        printf("ColorsInColorTable: \t%x (%u)\n", infoHeader.colorsInColorTable, infoHeader.colorsInColorTable);
        printf("ImportantColorCount:\t%x (%u)\n", infoHeader.importantColorsCount, infoHeader.importantColorsCount);
    }

    Rgb **Image::getPixelData() {
        return pixelData;
    }

    FileHeader *Image::getFileHeader() {
        return &fileHeader;
    }

    V3Header *Image::getInfoHeader() {
        return &infoHeader;
    }

    int32_t Image::getHeight() const {
        return infoHeader.height;
    }

    int32_t Image::getWidth() const {
        return infoHeader.width;
    }

    void Image::setHeight(int32_t height) {
        infoHeader.height = height;
    }

    void Image::setWidth(int32_t width) {
        infoHeader.width = width;
    }

}