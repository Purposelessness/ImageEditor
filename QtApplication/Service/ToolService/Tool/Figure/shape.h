#ifndef IMAGEEDITOR_SHAPE_H
#define IMAGEEDITOR_SHAPE_H

#include "ifigure.h"
#include "../tool.h"
#include "shapemodel.h"

class ToolUnitView;

class Shape : public IFigure, public Tool {
public:
    explicit Shape(QString name, ToolUnitView *view, ShapeModel *model);

    void setData(FigureData *figureData) override;

private:
    ShapeModel *model;
};


#endif //IMAGEEDITOR_SHAPE_H
