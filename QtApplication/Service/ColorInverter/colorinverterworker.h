#ifndef IMAGEEDITOR_COLORINVERTERWORKER_H
#define IMAGEEDITOR_COLORINVERTERWORKER_H


#include "../ColorInverter/colorinverter.h"
#include "../FigureCalculator/figurecalculator.h"

#include <QRectF>
#include <QImage>

struct TaskInput {
    const QImage &srcImage;
    FigurePoints points;
    QImage *destImage;
};

class ColorInverterWorker {
public:
    static QImage start(const FigurePoints& points, const QImage& image);
    static void test(const FigurePoints &points, const QImage &image);
    static QImage invertColorsSync(const QRectF &rect, const QImage &image);

private:
    static void invertColors(const TaskInput &input);
};


#endif //IMAGEEDITOR_COLORINVERTERWORKER_H
