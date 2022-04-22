#ifndef IMAGEEDITOR_COLORINVERTERWORKER_H
#define IMAGEEDITOR_COLORINVERTERWORKER_H


#include "../ColorInverter/colorinverter.h"

#include <QRectF>
#include <QImage>

struct TaskInput {
    const QImage &srcImage;
    int width, height;
    int xFrom, xTo;
    int yFrom, yTo;
    QImage *destImage;
};

class ColorInverterWorker {
public:
    static void test(QRectF &rect, const QImage &image);
    static QImage invertColorsSync(const QRectF &rect, const QImage &image);
    static QImage start(const QRectF &rect, const QImage &image);
    static void invertColors(const TaskInput &input);
};


#endif //IMAGEEDITOR_COLORINVERTERWORKER_H
