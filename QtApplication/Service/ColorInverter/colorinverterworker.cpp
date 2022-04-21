#include "colorinverterworker.h"
#include "../Benchmark/benchmark.h"

#include <QFuture>
#include <QtConcurrent>
#include <QThread>

static const int threadCount = QThread::idealThreadCount();

void ColorInverterWorker::test(QRectF &rect, const QImage &image) {
    Benchmark::start(10, start, rect, image);
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

QImage ColorInverterWorker::start(const QRectF &rect, const QImage &srcImage) {
    QImage image = srcImage;
    int dy = image.height() / threadCount;
    int y = 0;
    QVector<TaskInput> inputs;
    for (; y < image.height() - dy; y += dy) {
        inputs << TaskInput{image, 0, image.width(), y, y + dy, &image};
    }
    QFuture<void> future = QtConcurrent::map(inputs, invertColors);
    invertColors(TaskInput{image, 0, image.width(), y, image.height(), &image});
    future.waitForFinished();

    return image;
}

void ColorInverterWorker::invertColors(const TaskInput &input) {
    for (int y = input.yFrom; y < input.yTo; ++y) {
        uchar *line = input.destImage->scanLine(y);
        for (int x = input.xFrom; x < input.xTo; ++x) {
            QRgb pixel = input.srcImage.pixel(x, y);
            QRgb *newPixel = reinterpret_cast<QRgb *>(line + x);
            int red = 255 - qRed(pixel);
            int green = 255 - qGreen(pixel);
            int blue = 255 - qBlue(pixel);
            *newPixel = qRgb(red, green, blue);
        }
    }
}
