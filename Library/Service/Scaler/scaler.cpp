#include "scaler.h"

#include <cmath>

Bitmap::Image Scaler::startBmp(Bitmap::Image &image, int32_t nw, int32_t nh, const FigurePoints &points) {
    if (points.width == 0) {
        Bitmap::FileHeader fileHeader = *image.getFileHeader();
        Bitmap::InfoHeader infoHeader = *image.getInfoHeader();
        Rgb **data;

        int32_t ow, oh;
        ow = infoHeader.getWidth();
        oh = infoHeader.getHeight();

        fileHeader.fileSize = nw * nh * sizeof(Rgb) + nw % 4 + fileHeader.pixelArrayOffset;
        infoHeader.setWidth(nw);
        infoHeader.setHeight(nh);

        data = new Rgb *[nh];

        double scaleX = static_cast<double>(nw) / ow;
        double scaleY = static_cast<double>(nh) / oh;

        auto oldData = image.getPixelData();

        int32_t nx, ny;
        for (int32_t y = 0; y < nh; ++y) {
            data[y] = new Rgb[nw];
            for (int32_t x = 0; x < nw; ++x) {
                nx = static_cast<int32_t>(round(x / scaleX));
                ny = static_cast<int32_t>(round(y / scaleY));
                if (image.isPixelValid(nx, ny))
                    data[y][x] = oldData[ny][nx];
            }
        }

        Bitmap::Image nImage{fileHeader, infoHeader, data};
        return nImage;
    } else {
        Bitmap::FileHeader fileHeader = *image.getFileHeader();
        Bitmap::InfoHeader infoHeader = *image.getInfoHeader();
        Rgb **data;

        int32_t ow, oh;
        ow = points.width;
        oh = points.height;

        int32_t dx, dy;

        fileHeader.fileSize = nw * nh * sizeof(Rgb) + nw % 4 + fileHeader.pixelArrayOffset;
        infoHeader.setWidth(nw);
        infoHeader.setHeight(nh);

        data = new Rgb *[nh];

        double scaleX = static_cast<double>(nw) / ow;
        double scaleY = static_cast<double>(nh) / oh;

        dx = points.x;
        dy = points.y;

        auto oldData = image.getPixelData();

        int32_t nx, ny;
        for (int32_t y = 0; y < nh; ++y) {
            data[y] = new Rgb[nw];
            for (int32_t x = 0; x < nw; ++x) {
                nx = static_cast<int32_t>(round(dx + x / scaleX));
                ny = static_cast<int32_t>(round(dy + y / scaleY));
                if (image.isPixelValid(nx, ny))
                    data[y][x] = oldData[ny][nx];
            }
        }

        Bitmap::Image nImage{fileHeader, infoHeader, data};
        return nImage;
    }
}
