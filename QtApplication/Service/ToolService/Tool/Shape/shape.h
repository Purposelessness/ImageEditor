#ifndef IMAGEEDITOR_SHAPE_H
#define IMAGEEDITOR_SHAPE_H

#include "../tool.h"
#include "shapemodel.h"

class ToolUnitView;

class Shape : public Tool {
public:
    explicit Shape(QString name, ToolUnitView *view, ShapeModel *model);

    void setFillColor(const QColor& color);
    void setLineColor(const QColor &color);
    void setThickness(const int &value);

private:
    ShapeModel *model;
};


#endif //IMAGEEDITOR_SHAPE_H
