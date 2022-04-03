#ifndef IMAGEEDITOR_IFIGURE_H
#define IMAGEEDITOR_IFIGURE_H

#include "../tool.h"

#include <QColor>

struct FigureData {
    QColor fillColor {QColor(Qt::green)};
    QColor lineColor {QColor(Qt::black)};
    int thickness {10};
};

enum FigureType {
    line,
    shape,
    none
};

class IFigure : public Tool {
Q_OBJECT

public:
    explicit IFigure(QString name, ToolUnitView *view, IToolModel *model);

    virtual void setData(FigureData *figureData) = 0;

signals:
    void showParametersInterface(FigureType type);
};

#endif //IMAGEEDITOR_IFIGURE_H
