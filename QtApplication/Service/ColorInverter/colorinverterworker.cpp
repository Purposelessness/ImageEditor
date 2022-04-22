#include "colorinverterworker.h"
#include "../Benchmark/benchmark.h"

#include <QFuture>
#include <QtConcurrent>
#include <QThread>

static const int threadCount = QThread::idealThreadCount();
static const QRgb mask = 0xFFFFFFFF;

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
    QImage image(srcImage.size(), QImage::Format_RGB32);
    int xFrom = static_cast<int>(rect.left()), xTo = static_cast<int>(rect.right());
    int yFrom = static_cast<int>(rect.top()), yTo = static_cast<int>(rect.bottom());
    int height = image.height();
    int width = image.width();
    int dy = image.height() / threadCount;
    int y = 0;
    QVector<TaskInput> inputs;
    for (; y < height - dy; y += dy) {
        inputs << TaskInput{srcImage, width, height, xFrom, xTo, yFrom, yTo, &image};
    }
    QFuture<void> future = QtConcurrent::map(inputs, invertColors);
    invertColors(TaskInput{srcImage, width, height, xFrom, xTo, yFrom, yTo, &image});
    future.waitForFinished();

    return image;
}

void ColorInverterWorker::invertColors(const TaskInput &input) {
    for (int y = 0; y < input.height; ++y) {
        QRgb *line = reinterpret_cast<QRgb *>(input.destImage->scanLine(y));
        for (int x = 0; x < input.width; ++x) {
            QRgb pixel = input.srcImage.pixel(x, y);
            if (input.xFrom <= x && x < input.xTo && input.yFrom <= y && y < input.yTo)
                pixel = mask - pixel;
            line[x] = pixel;
        }
    }
}
