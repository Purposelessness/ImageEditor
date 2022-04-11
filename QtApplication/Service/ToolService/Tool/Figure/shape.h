#ifndef IMAGEEDITOR_SHAPE_H
#define IMAGEEDITOR_SHAPE_H

#include "figure.h"
#include "shapemodel.h"

class ToolUnitView;

class Shape : public Figure {
Q_OBJECT

public:
    explicit Shape(QString name, ToolUnitView *view, ShapeModel *model);

    void setData(FigureData *figureData) override;
    FigureType getType() override;

private:
    ShapeModel *model;
};


#endif //IMAGEEDITOR_SHAPE_H
