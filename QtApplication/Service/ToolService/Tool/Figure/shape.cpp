#include "shape.h"

#include <utility>

Shape::Shape(QString name, ToolUnitView *view, ShapeModel *model) : IFigure(std::move(name), view, model), model(model) {
    connect(model, SIGNAL(shapeDrawn()), this, SLOT(onShapeDrawn()));
}

void Shape::setData(FigureData *figureData) {
    model->setFillColor(figureData->fillColor);
    model->setLineColor(figureData->lineColor);
    model->setThickness(figureData->thickness);
}

void Shape::onShapeDrawn() {
    emit showParametersInterface(shape);
}

FigureType Shape::getType() {
    return shape;
}

void Shape::unlock() {
    model->unlock();
}

void Shape::lock() {
    model->lock();
}
