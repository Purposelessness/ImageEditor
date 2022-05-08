#include "shape.h"

template<typename T>
Shape<T>::Shape(const QString &name, CommandType type, ShapeModel<T> *model) : Figure(name, model), model(model) {
    model->setType(type);
}

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
    return FigureType::shape;
}
