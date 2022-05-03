#ifndef IMAGEEDITOR_COLORINVERTERWORKER_H
#define IMAGEEDITOR_COLORINVERTERWORKER_H


#include "../../../Library/FigureCalculator/figurecalculator.h"

#include <QRectF>
#include <QImage>

struct TaskInput {
    TaskInput(const TaskInput &other) : srcImage(other.srcImage), points(other.points), destImage(other.destImage) {}

    TaskInput(const QImage &image, const FigurePoints &points, QImage *destImage)
            : srcImage(image), points(points), destImage(destImage) {}

    TaskInput &operator=(const TaskInput &other) noexcept {
        return *new(this) TaskInput(other.srcImage, other.points, other.destImage);
    }

    TaskInput &operator=(TaskInput &&other) noexcept {
        return *new(this) TaskInput(other.srcImage, other.points, other.destImage);
    }

    const QImage &srcImage = QImage();
    FigurePoints points;
    QImage *destImage = nullptr;
};

class ColorInverterWorker {
public:
    static QImage start(const FigurePoints &points, const QImage &image);
    static void test(const FigurePoints &points, const QImage &image);

private:
    static void invertColors(const TaskInput &input);
};


#endif //IMAGEEDITOR_COLORINVERTERWORKER_H
