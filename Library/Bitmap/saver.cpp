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

        auto rect = image->getCropRect();
        auto fileHeader = image->getFileHeader();
        auto infoHeader = image->getInfoHeader();

        Rgb **croppedData = nullptr;
        Rgb **pixelData = image->getPixelData();
        int32_t width, height;
        if (rect.isNull()) {
            height = infoHeader->getHeight();
            width = infoHeader->getWidth();
        } else {
            int32_t x0 = rect.x < 0 ? 0 : rect.x;
            int32_t y0 = rect.y < 0 ? 0 : rect.y;
            x0 = x0 > image->getWidth() ? image->getHeight() - 1 : x0;
            y0 = y0 > image->getHeight() ? image->getWidth() - 1 : y0;
            height = rect.y + rect.height > image->getHeight() ? image->getHeight() - rect.y : rect.height;
            width = rect.x + rect.width > image->getWidth() ? image->getWidth() - rect.x : rect.width;
            croppedData = new Rgb *[height];
            for (int32_t y = 0; y < height; ++y) {
                croppedData[y] = new Rgb[width];
                for (int32_t x = 0; x < width; ++x) {
                    croppedData[y][x] = pixelData[y + y0][x + x0];
                }
            }
            infoHeader->setWidth(width);
            infoHeader->setHeight(height);
        }

        if (!infoHeader->isUpsideDown) {
            infoHeader->setHeight(-height);
        }

        fwrite(fileHeader, sizeof(FileHeader), 1, f);
        fwrite(&infoHeader->size, sizeof(uint32_t), 1, f);
        fwrite(&infoHeader->data, infoHeader->size, 1, f);

        size_t lineSize = width * sizeof(Rgb) + width % 4;
        auto writeData = !croppedData ? pixelData : croppedData;
        for (int32_t i = height - 1; i > -1; --i) {
            fwrite(writeData[i], 1, lineSize, f);
        }
        delete[] croppedData;

        fclose(f);
    }

} // Bitmap