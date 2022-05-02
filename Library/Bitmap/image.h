#ifndef IMAGEEDITOR_IMAGE_H
#define IMAGEEDITOR_IMAGE_H


#include <string>

namespace Bitmap {

#pragma pack(push, 1)
    struct BitmapFileHeader {
        unsigned short signature;
        unsigned int fileSize;
        unsigned short reserved1;
        unsigned short reserved2;
        unsigned int pixelArrayOffset;
    };

    struct BitmapInfoHeader {
        unsigned int headerSize;
        unsigned int width;
        unsigned int height;
        unsigned int planes;
        unsigned int bitsPerPixel;
        unsigned int compression;
        unsigned int imageSize;
        unsigned int xPixelsPerMeter;
        unsigned int yPixelsPerMeter;
        unsigned int colorsInColorTable;
        unsigned int importantColorCount;
    };

    struct Rgb {
        unsigned char b;
        unsigned char g;
        unsigned char r;
    };
#pragma pack(pop)

    class Image {
    public:
        void read(const char *path);
        void write(const char *path);

        void printFileHeader() const;
        void printInfoHeader() const;

    private:
        void swap(unsigned char *a, unsigned char *b);

        BitmapFileHeader fileHeader;
        BitmapInfoHeader infoHeader;
        Rgb **pixelData = nullptr;
    };

}


#endif //IMAGEEDITOR_IMAGE_H
