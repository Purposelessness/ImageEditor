#include "glue.h"

void Glue::start(Bitmap::Image *image1, Bitmap::Image *image2) {
    auto fh1 = image1->getFileHeader();
    auto ih1 = image1->getInfoHeader();
    auto w1 = image1->getWidth();
    auto h1 = image1->getHeight();
    auto w2 = image2->getWidth();
    auto h2 = image2->getHeight();

    auto data1 = image1->getPixelData();
    auto data2 = image2->getPixelData();

    auto nw = w1 + w2;
    auto nh = max(h1, h2);

    auto newData = new Rgb *[nh];
    for (auto y = 0; y < nh; ++y) {
        newData[y] = new Rgb[nw];
        for (auto x = 0; x < nw; ++x) {
            newData[y][x] = {255, 255, 255};
        }
    }

    for (auto y = 0; y < h1; ++y) {
        for (auto x = 0; x < w1; ++x) {
            newData[y][x] = data1[y][x];
        }
    }
    for (auto y = 0; y < h2; ++y) {
        for (auto x = 0; x < w2; ++x) {
            newData[y][w1 + x] = data2[y][x];
        }
    }

    auto nfh = *fh1;
    auto nih = *ih1;

    nfh.fileSize = nw * nh * sizeof(Rgb) + nw % 4 + nfh.pixelArrayOffset;
    nih.setWidth(nw);
    nih.setHeight(nh);

    image1->setNewImage(nfh, nih, newData);
}

int32_t Glue::max(int32_t a, int32_t b) {
    return a > b ? a : b;
}
