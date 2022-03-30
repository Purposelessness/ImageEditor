#ifndef IMAGEEDITOR_SHAPE_H
#define IMAGEEDITOR_SHAPE_H

#include "../tool.h"
#include "shapemodel.h"

class ToolUnitView;

class Shape : public Tool {
public:
    explicit Shape(QString name, ToolUnitView *view, ShapeModel *model);

public slots:
    void update();
};


#endif //IMAGEEDITOR_SHAPE_H
