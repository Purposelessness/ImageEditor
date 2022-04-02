#include "line.h"

Line::Line(QString name, ToolUnitView *view, LineModel *model) : Tool(std::move(name), view, model), model(model) {}

void Line::setData(FigureData *figureData) {
    model->setColor(figureData->lineColor);
    model->setThickness(figureData->thickness);
}
