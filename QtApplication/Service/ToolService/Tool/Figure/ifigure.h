#ifndef IMAGEEDITOR_IFIGURE_H
#define IMAGEEDITOR_IFIGURE_H

#include <QColor>

struct FigureData {
    QColor fillColor {QColor(Qt::green)};
    QColor lineColor {QColor(Qt::black)};
    int thickness {10};
};

class IFigure {
public:
    virtual void setData(FigureData *figureData) = 0;
};

#endif //IMAGEEDITOR_IFIGURE_H
