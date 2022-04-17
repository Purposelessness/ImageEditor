#include "shape.h"

Shape::Shape(const QString &name, ShapeModel *model) : Figure(name, model), model(model) {}

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
