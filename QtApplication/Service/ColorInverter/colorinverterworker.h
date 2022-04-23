#ifndef IMAGEEDITOR_COLORINVERTERWORKER_H
#define IMAGEEDITOR_COLORINVERTERWORKER_H


#include "../ColorInverter/colorinverter.h"

#include <QRectF>
#include <QImage>

struct TaskInput {
    const QImage &srcImage;
    int width, height;
    int **data;
    int xSize, ySize;
//    int xFrom, xTo;
//    int yFrom, yTo;
    QImage *destImage;
};

class ColorInverterWorker {
public:
    static QImage start(const QRectF &rect, const QImage &image);
    static void invertColors(const TaskInput &input);
    static void test(QRectF &rect, const QImage &image);
    static QImage invertColorsSync(const QRectF &rect, const QImage &image);
};


#endif //IMAGEEDITOR_COLORINVERTERWORKER_H
