#ifndef IMAGEEDITOR_SHAPE_H
#define IMAGEEDITOR_SHAPE_H

#include "figure.h"
#include "shapemodel.h"

class ToolUnitView;

template<typename T>
class Shape : public Figure {
public:
    explicit Shape(const QString &name, CommandType type = CommandType::none, ShapeModel<T> *model = new ShapeModel<T>());

    void setData(const FigureData &figureData) override;
    FigureType getType() override;

private:
    ShapeModel<T> *model;
};

#include "shape.inl"


#endif //IMAGEEDITOR_SHAPE_H
