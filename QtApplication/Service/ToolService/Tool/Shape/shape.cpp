#include "shape.h"

#include <utility>

Shape::Shape(QString name, ToolUnitView *view, ShapeModel *model) : Tool(std::move(name), view, model), model(model) {}

void Shape::setFillColor(const QColor &color) {
    model->setFillColor(color);
}

void Shape::setLineColor(const QColor &color) {
    model->setLineColor(color);
}

void Shape::setThickness(const int &value) {
    model->setThickness(value);
}
