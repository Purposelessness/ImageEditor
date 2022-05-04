#include "saver.h"

#include <cstdio>

namespace Bitmap {

    void Saver::save(Image *image, const char *path) {
        if (image->isEmpty()) {
            printf("IImage is empty\n");
            return;
        }

        FILE *f = fopen(path, "wb");

        if (!f) {
            printf("Cannot open file %s\n", path);
            return;
        }

        auto pixelData = image->getPixelData();
        auto fileHeader = image->getFileHeader();
        auto infoHeader = image->getInfoHeader();

        int32_t height = infoHeader->getHeight();
        int32_t width = infoHeader->getWidth();

        if (!infoHeader->isUpsideDown) {
            infoHeader->setHeight(-height);
        }

        fwrite(fileHeader, sizeof(FileHeader), 1, f);
        fwrite(&infoHeader->size, sizeof(uint32_t), 1, f);
        fwrite(&infoHeader->data, infoHeader->size, 1, f);

        size_t lineSize = width * sizeof(Rgb) + width % 4;
        for (int32_t i = height - 1; i > -1; --i) {
            fwrite(pixelData[i], 1, lineSize, f);
        }

        fclose(f);
    }

} // Bitmap