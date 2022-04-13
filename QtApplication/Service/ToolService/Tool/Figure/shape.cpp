#include "shape.h"

#include <utility>

Shape::Shape(QString name, ToolUnitView *view, ShapeModel *model) : Figure(std::move(name), view, model), model(model) {}

void Shape::setData(const FigureData &figureData) {
    if (figureData.fillEnabled) {
        model->setFillColor(figureData.fillColor);
    } else {
        model->setFillColor();
    }
    if (figureData.lineEnabled) {
        model->setLineColor(figureData.lineColor);
    } else {
        model->setLineColor();
    }
    model->setThickness(figureData.thickness);
}

FigureType Shape::getType() {
    return shape;
}
