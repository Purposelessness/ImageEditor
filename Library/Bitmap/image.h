#ifndef IMAGEEDITOR_IMAGE_H
#define IMAGEEDITOR_IMAGE_H


#include <string>

namespace Bitmap {

#pragma pack(push, 1)
    struct BitmapFileHeader {
        uint16_t signature;
        uint32_t fileSize;
        uint16_t reserved1;
        uint16_t reserved2;
        uint32_t pixelArrayOffset;
    };

    struct BitmapInfoHeader {
        uint32_t headerSize;
        uint32_t width;
        uint32_t height;
        uint32_t planes;
        uint32_t bitsPerPixel;
        uint32_t compression;
        uint32_t imageSize;
        uint32_t xPixelsPerMeter;
        uint32_t yPixelsPerMeter;
        uint32_t colorsInColorTable;
        uint32_t importantColorCount;
    };

    struct Rgb {
        uint8_t b;
        uint8_t g;
        uint8_t r;
    };
#pragma pack(pop)

    class Image {
    public:
        Image() = default;
        explicit Image(const BitmapFileHeader &fileHeader, const BitmapInfoHeader &infoHeader, Rgb **pixelData);
        ~Image();

        [[nodiscard]] bool isEmpty() const;

        void printFileHeader() const;
        void printInfoHeader() const;

        Rgb **getPixelData();
        BitmapFileHeader *getFileHeader();
        BitmapInfoHeader *getInfoHeader();

    private:
        void swap(unsigned char *a, unsigned char *b);

        BitmapFileHeader fileHeader{};
        BitmapInfoHeader infoHeader{};
        Rgb **pixelData = nullptr;
    };

}


#endif //IMAGEEDITOR_IMAGE_H
