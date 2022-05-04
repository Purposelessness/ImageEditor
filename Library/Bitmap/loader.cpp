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
        Rgb **pixelData;

        fread(&fileHeader, sizeof(FileHeader), 1, f);

        uint32_t size;
        fread(&size, sizeof(uint32_t), 1, f);
        InfoHeader infoHeader{size};

        fread(&infoHeader.data, size, 1, f);

        int32_t height = infoHeader.getHeight();
        int32_t width = infoHeader.getWidth();

        infoHeader.isUpsideDown = height > 0;
        if (!infoHeader.isUpsideDown) {
            height = -height;
            infoHeader.setHeight(-height);
        }

        pixelData = new Rgb *[height];
        size_t lineSize = width * sizeof(Rgb) + width % 4;
        if (infoHeader.isUpsideDown) {
            for (int32_t i = height - 1; i > -1; --i) {
                pixelData[i] = reinterpret_cast<Rgb *>(malloc(lineSize));
                fread(pixelData[i], 1, lineSize, f);
            }
        } else {
            for (int i = 0; i < height; ++i) {
                pixelData[i] = reinterpret_cast<Rgb *>(malloc(lineSize));
                fread(pixelData[i], 1, lineSize, f);
            }
        }

        fclose(f);

        return Image(fileHeader, infoHeader, pixelData);
    }

} // IImage