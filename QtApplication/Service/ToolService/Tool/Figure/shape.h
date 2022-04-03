#ifndef IMAGEEDITOR_SHAPE_H
#define IMAGEEDITOR_SHAPE_H

#include "ifigure.h"
#include "shapemodel.h"

class ToolUnitView;

class Shape : public IFigure {
Q_OBJECT

public:
    explicit Shape(QString name, ToolUnitView *view, ShapeModel *model);

    void setData(FigureData *figureData) override;

protected slots:
    void onShapeDrawn();

private:
    ShapeModel *model;
};


#endif //IMAGEEDITOR_SHAPE_H
