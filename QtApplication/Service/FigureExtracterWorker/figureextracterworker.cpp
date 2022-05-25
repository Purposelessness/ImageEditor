#include "figureextractorworker.h"

static const QRgb transparent = 0x00000000;

QImage FigureExtractorWorker::start(const FigurePoints& points, const QImage& srcImage) {
    QImage image(srcImage.size(), QImage::Format_ARGB32);

    TaskInput input{srcImage, points, &image};
    extractFigure(input);

    return image;
}

void FigureExtractorWorker::extractFigure(const TaskInput &input) {
    const int width = input.srcImage.width();
    const int height = input.srcImage.height();

    for (int y = 0; y < height; ++y) {
        auto *line = reinterpret_cast<QRgb *>(input.destImage->scanLine(y));
        for (int x = 0; x < width; ++x) {
            if (!input.points.contains(x, y))
                continue;
            int xRect = x - input.points.x;
            int yRect = y - input.points.y;
            line[x] = input.points.data[yRect][xRect] == FillType::fill ? input.srcImage.pixel(x, y) : transparent;
        }
    }
}
