#include "line.h"

Line::Line(const QString &name, LineModel *model) : Figure(name, model), model(model) {}

void Line::setData(const FigureData &figureData) {
    model->setColor(figureData.lineColor);
    model->setThickness(figureData.thickness);
}

FigureType Line::getType() {
    return line;
}
