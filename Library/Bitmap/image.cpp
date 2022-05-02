#include "image.h"

#include <cstdio>

void Bitmap::Image::printFileHeader() const {
    printf("Signature:          \t%x (%hu)\n", fileHeader.signature, fileHeader.signature);
    printf("FileSize:           \t%x (%u)\n", fileHeader.fileSize, fileHeader.fileSize);
    printf("Reserved1:          \t%x (%hu)\n", fileHeader.reserved1, fileHeader.reserved1);
    printf("Reserved2:          \t%x (%hu)\n", fileHeader.reserved2, fileHeader.reserved2);
    printf("PixelArrayOffset:   \t%x (%u)\n", fileHeader.pixelArrayOffset, fileHeader.pixelArrayOffset);
}

void Bitmap::Image::printInfoHeader() const {
    printf("HeaderSize:         \t%x (%u)\n", infoHeader.headerSize, infoHeader.headerSize);
    printf("Width:              \t%x (%u)\n", infoHeader.width, infoHeader.width);
    printf("Height:             \t%x (%u)\n", infoHeader.height, infoHeader.height);
    printf("Planes:             \t%x (%hu)\n", infoHeader.planes, infoHeader.planes);
    printf("BitsPerPixel:       \t%x (%hu)\n", infoHeader.bitsPerPixel, infoHeader.bitsPerPixel);
    printf("Compression:        \t%x (%u)\n", infoHeader.compression, infoHeader.compression);
    printf("ImageSize:          \t%x (%u)\n", infoHeader.imageSize, infoHeader.imageSize);
    printf("XPixelsPerMeter:    \t%x (%u)\n", infoHeader.xPixelsPerMeter, infoHeader.xPixelsPerMeter);
    printf("YPixelsPerMeter:    \t%x (%u)\n", infoHeader.yPixelsPerMeter, infoHeader.yPixelsPerMeter);
    printf("ColorsInColorTable: \t%x (%u)\n", infoHeader.colorsInColorTable, infoHeader.colorsInColorTable);
    printf("ImportantColorCount:\t%x (%u)\n", infoHeader.importantColorCount, infoHeader.importantColorCount);
}

void Bitmap::Image::read(const char *path) {
    FILE *f = fopen(path, "rb");

    if (!f) {
        printf("Cannot open file %s\n", path);
        return;
    }

    fread(&fileHeader, 1, sizeof(BitmapFileHeader), f);
    fread(&infoHeader, 1, sizeof(BitmapInfoHeader), f);

    printFileHeader();
    printInfoHeader();

    unsigned int height = infoHeader.height;
    unsigned int width = infoHeader.width;

    pixelData = new Rgb *[height];
    size_t lineSize = width * sizeof(Rgb) + width % 4;
    for (int i = 0; i < height; ++i) {
        pixelData[i] = reinterpret_cast<Rgb *>(malloc(lineSize));
        fread(pixelData[i], 1, lineSize, f);
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            swap(&pixelData[i][j].r, &pixelData[i][j].g);
        }
    }

    fclose(f);
}

void Bitmap::Image::swap(unsigned char *a, unsigned char *b) {
    unsigned char t = *a;
    *a = *b;
    *b = t;
}

void Bitmap::Image::write(const char *path) {
    if (!pixelData) {
        printf("Image is empty\n");
        return;
    }

    FILE *f = fopen(path, "wb");

    if (!f) {
        printf("Cannot open file %s\n", path);
        return;
    }

    fwrite(&fileHeader, 1, sizeof(BitmapFileHeader), f);
    fwrite(&infoHeader, 1, sizeof(BitmapInfoHeader), f);

    unsigned int height = infoHeader.height;
    unsigned int width = infoHeader.width;

    size_t lineSize = width * sizeof(Rgb) + width % 4;
    for (int i = 0; i < height; ++i) {
        fwrite(pixelData[i], 1, lineSize, f);
    }

    fclose(f);
}
