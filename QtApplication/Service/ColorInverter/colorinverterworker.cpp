#include "colorinverterworker.h"
#include "../Benchmark/benchmark.h"

#include <QFuture>
#include <QtConcurrent>
#include <QThread>

static const int threadCount = QThread::idealThreadCount();
static const QRgb mask = 0xFFFFFFFF;

void ColorInverterWorker::test(const FigurePoints &points, const QImage &image) {
    Benchmark::start(10, start, points, image);
}

QImage ColorInverterWorker::start(const FigurePoints &points, const QImage &srcImage) {
    QImage image(srcImage.size(), QImage::Format_RGB32);

    const int width = image.width();
    const int height = image.height();
    const int dy = image.height() / threadCount;
    int y = 0;

    QVector<TaskInput> inputs;
    for (; y < height - dy; y += dy) {
        inputs << TaskInput{srcImage, points, &image};
    }
    inputs << TaskInput{srcImage, points, &image};
    QFuture<void> future = QtConcurrent::map(inputs, invertColors);
    future.waitForFinished();

    return image;
}

void ColorInverterWorker::invertColors(const TaskInput &input) {
    const int width = input.srcImage.width();
    const int height = input.srcImage.height();
    int x_1 = input.points.x;
    int x_2 = x_1 + input.points.width;
    int y_1 = input.points.y;
    int y_2 = y_1 + input.points.height;

    bool figureDrawn = false;

    for (int y = 0; y < height; ++y) {
        QRgb *line = reinterpret_cast<QRgb *>(input.destImage->scanLine(y));
        for (int x = 0; x < width; ++x) {
            QRgb pixel = input.srcImage.pixel(x, y);
            if (input.points.contains(x, y)) {
                int xRect = x - input.points.x;
                int yRect = y - input.points.y;
                if (input.points.data[yRect][xRect])
                    pixel = mask - pixel;
            }
            line[x] = pixel;
        }
    }
}

QImage ColorInverterWorker::invertColorsSync(const QRectF &rect, const QImage &rawImage) {
    QImage image = rawImage;
    int x_0 = static_cast<int>(rect.x()), y_0 = static_cast<int>(rect.y());
    auto width = static_cast<int>(rect.width()), height = static_cast<int>(rect.height());
    auto size = static_cast<size_t>(rect.width() * rect.height());
    auto *pixelData = new PixelData[size];
    for (int x = 0, i = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y, ++i) {
            int x_1 = x_0 + x, y_1 = y_0 + y;
            auto rgb = image.pixel(x_1, y_1);
            pixelData[i] = {x_1, y_1, qRed(rgb), qGreen(rgb), qBlue(rgb)};
        }
    }
    ColorInverter::invert(pixelData, size);
    for (int i = 0; i < size; ++i) {
        auto data = pixelData[i];
        image.setPixel(data.x, data.y, qRgb(data.red, data.green, data.blue));
    }
    return image;
}
