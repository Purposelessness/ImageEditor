#include "line.h"

Line::Line(QString name, ToolUnitView *view, LineModel *model) : Figure(std::move(name), view, model), model(model) {}

void Line::setData(const FigureData &figureData) {
    model->setColor(figureData.lineColor);
    model->setThickness(figureData.thickness);
}

FigureType Line::getType() {
    return line;
}
