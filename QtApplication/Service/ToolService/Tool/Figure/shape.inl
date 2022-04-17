#include "shape.h"

template<typename T>
Shape<T>::Shape(const QString &name, ShapeModel<T> *model) : Figure(name, model), model(model) {}

template<typename T>
void Shape<T>::setData(const FigureData &figureData) {
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

template<typename T>
FigureType Shape<T>::getType() {
    return shape;
}
