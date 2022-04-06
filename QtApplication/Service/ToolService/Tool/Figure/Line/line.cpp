#include "line.h"

Line::Line(QString name, ToolUnitView *view, LineModel *model) : Figure(std::move(name), view, model), model(model) {
    connect(model, SIGNAL(itemSelected()), this, SLOT(onItemSelected()));
    connect(model, SIGNAL(itemDeselected()), this, SLOT(onItemDeselected()));
}

void Line::setData(FigureData *figureData) {
    if (figureData->lineColor.isValid())
        model->setColor(figureData->lineColor);
    model->setThickness(figureData->thickness);
}

FigureType Line::getType() {
    return line;
}

void Line::onItemSelected() {
    emit selected(this);
}

void Line::onItemDeselected() {
    emit deselected();
}
