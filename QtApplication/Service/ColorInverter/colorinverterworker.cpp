#include "colorinverterworker.h"
#include "../Benchmark/benchmark.h"

static const QRgb mask = 0xFFFFFFFF;
static const QRgb opaque = 0xFF000000;
static const QRgb transparent = 0x00000000;

void ColorInverterWorker::test(const FigurePoints &points, const QImage &image) {
    Benchmark::start(10, start, points, image);
}

QImage ColorInverterWorker::start(const FigurePoints& points, const QImage& srcImage) {
    QImage image(srcImage.size(), QImage::Format_ARGB32);

    TaskInput input{srcImage, points, &image};
    invertColors(input);

    return image;
}

void ColorInverterWorker::invertColors(const TaskInput &input) {
    const int width = input.srcImage.width();
    const int height = input.srcImage.height();

    for (int y = 0; y < height; ++y) {
        auto *line = reinterpret_cast<QRgb *>(input.destImage->scanLine(y));
        for (int x = 0; x < width; ++x) {
            if (input.points.contains(x, y)) {
                int xRect = x - input.points.x;
                int yRect = y - input.points.y;
                if (input.points.data[yRect][xRect] != none) {
                    QRgb pixel = input.srcImage.pixel(x, y);
                    pixel = mask - pixel;
                    pixel += opaque;
                    line[x] = pixel;
                    continue;
                }
            }
            line[x] = transparent;
        }
    }
}
