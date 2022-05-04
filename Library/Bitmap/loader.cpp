#include "loader.h"

#include <cstdio>
#include <malloc.h>

namespace Bitmap {

    Image Loader::load(const char *path) {
        FILE *f = fopen(path, "rb");

        if (!f) {
            printf("Cannot open file %s\n", path);
            return Image{};
        }

        FileHeader fileHeader{};
        V3Header infoHeader{};
        Rgb **pixelData;

        fread(&fileHeader, 1, sizeof(FileHeader), f);
        fread(&infoHeader, 1, sizeof(V3Header), f);

        uint32_t height = infoHeader.height;
        uint32_t width = infoHeader.width;

        pixelData = new Rgb *[height];
        size_t lineSize = width * sizeof(Rgb) + width % 4;
        for (int i = 0; i < height; ++i) {
            pixelData[i] = reinterpret_cast<Rgb *>(malloc(lineSize));
            fread(pixelData[i], 1, lineSize, f);
        }

        fclose(f);

        return Image(fileHeader, infoHeader, pixelData);
    }

} // IImage