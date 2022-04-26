#include "colorinverterworker.h"
#include "../Benchmark/benchmark.h"

#include <QFuture>
#include <QtConcurrent>
#include <QThread>

static const QRgb mask = 0xFFFFFFFF;

void ColorInverterWorker::test(const FigurePoints &points, const QImage &image) {
    Benchmark::start(10, start, points, image);
}

QImage ColorInverterWorker::start(const FigurePoints& points, const QImage& srcImage) {
    QImage image(srcImage.size(), QImage::Format_RGB32);

    TaskInput input{srcImage, points, &image};
    invertColors(input);

    return image;
}

void ColorInverterWorker::invertColors(const TaskInput &input) {
    const int width = input.srcImage.width();
    const int height = input.srcImage.height();

    for (int y = 0; y < height; ++y) {
        QRgb *line = reinterpret_cast<QRgb *>(input.destImage->scanLine(y));
        for (int x = 0; x < width; ++x) {
            QRgb pixel = input.srcImage.pixel(x, y);
            if (input.points.contains(x, y)) {
                int xRect = x - input.points.x;
                int yRect = y - input.points.y;
                if (input.points.data[yRect][xRect]) {
                    pixel = mask - pixel;
                }
            }
            line[x] = pixel;
        }
    }
}
