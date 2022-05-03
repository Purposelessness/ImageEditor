#ifndef IMAGEEDITOR_IMAGE_H
#define IMAGEEDITOR_IMAGE_H


#include "../iimage.h"

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
#pragma pack(pop)

    class Image : public IImage {
    public:
        Image() = default;
        explicit Image(const BitmapFileHeader &fileHeader, const BitmapInfoHeader &infoHeader, Rgb **pixelData);
        ~Image();

        [[nodiscard]] bool isEmpty() const override;

        void printFileHeader() const;
        void printInfoHeader() const;

        void setHeight(uint32_t height) override;
        void setWidth(uint32_t width) override;

        Rgb **getPixelData() override;
        [[nodiscard]] uint32_t getHeight() const override;
        [[nodiscard]] uint32_t getWidth() const override;
        BitmapFileHeader *getFileHeader();
        BitmapInfoHeader *getInfoHeader();

    private:
        BitmapFileHeader fileHeader{};
        BitmapInfoHeader infoHeader{};
        Rgb **pixelData = nullptr;
    };

}


#endif //IMAGEEDITOR_IMAGE_H
