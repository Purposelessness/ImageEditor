#include "scaler.h"

#include <cmath>

Bitmap::Image Scaler::startBmp(Bitmap::Image &image, int32_t nw, int32_t nh, const FigurePoints &points) {
    Bitmap::FileHeader fileHeader = *image.getFileHeader();
    Bitmap::InfoHeader infoHeader = *image.getInfoHeader();
    Rgb **data;

    int32_t dx, dy;
    int32_t ow, oh;

    if (points.width == 0) {
        dx = dy = 0;
        ow = infoHeader.getWidth();
        oh = infoHeader.getHeight();
    } else {
        ow = points.width;
        oh = points.height;
        dx = points.x;
        dy = points.y;
    }

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
            nx = static_cast<int32_t>(round(dx + x / scaleX));
            ny = static_cast<int32_t>(round(dy + y / scaleY));
            if (image.isPixelValid(nx, ny))
                data[y][x] = oldData[ny][nx];
        }
    }

    Bitmap::Image nImage{fileHeader, infoHeader, data};
    return nImage;
}

FigurePoints Scaler::startPoints(const FigurePoints &figurePoints, int32_t newWidth, int32_t newHeight) {
    auto nPoints = FigurePoints{0, 0, newWidth, newHeight};

    double scaleX = static_cast<double>(newWidth) / figurePoints.width;
    double scaleY = static_cast<double>(newHeight) / figurePoints.height;

    nPoints.x = static_cast<int32_t>(round(figurePoints.x / scaleX));
    nPoints.y = static_cast<int32_t>(round(figurePoints.y / scaleY));

    int32_t nx, ny;
    for (int32_t y = 0; y < newHeight; ++y) {
        for (int32_t x = 0; x < newWidth; ++x) {
            nx = static_cast<int32_t>(round(x / scaleX));
            ny = static_cast<int32_t>(round(y / scaleY));
            if (figurePoints.isValid(nx, ny))
                nPoints.data[y][x] = figurePoints.data[ny][nx];
        }
    }

    return nPoints;
}

Point Scaler::startPoint(const Point &point, double scale) {
    return {static_cast<int32_t>(round(point.x / scale)), static_cast<int32_t>(round(point.y / scale))};
}
