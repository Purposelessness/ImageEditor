#include "line.h"

Line::Line(QString name, ToolUnitView *view, LineModel *model) : IFigure(std::move(name), view, model), model(model) {
    connect(model, SIGNAL(lineDrawn()), this, SLOT(onLineDrawn()));
}

void Line::setData(FigureData *figureData) {
    if (figureData->lineColor.isValid())
        model->setColor(figureData->lineColor);
    model->setThickness(figureData->thickness);
}

void Line::onLineDrawn() {
    emit showParametersInterface(line);
}

FigureType Line::getType() {
    return line;
}
