#include "saver.h"

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

        fwrite(fileHeader, 1, sizeof(BitmapFileHeader), f);
        fwrite(infoHeader, 1, sizeof(BitmapInfoHeader), f);

        uint32_t height = infoHeader->height;
        uint32_t width = infoHeader->width;

        size_t lineSize = width * sizeof(Rgb) + width % 4;
        for (int i = 0; i < height; ++i) {
            fwrite(pixelData[i], 1, lineSize, f);
        }

        fclose(f);
    }

} // Bitmap