#include "figure.h"

#include <utility>

Figure::Figure(QString name, ToolUnitView *view, FigureModel *model) : Tool(std::move(name), view, model),
                                                                       model(model) {
    connect(model, SIGNAL(itemSelected()), this, SLOT(onItemSelected()));
    connect(model, SIGNAL(itemDeselected()), this, SLOT(onItemDeselected()));
}

void Figure::onMousePressed(const QPoint &mousePos, IGraphicsView *graphicsView) {
    if (isSelected)
        return;
    emit update(this);
    Tool::onMousePressed(mousePos, graphicsView);
}

void Figure::onMouseMoved(const QPoint &mousePos) {
    if (isSelected)
        return;
    Tool::onMouseMoved(mousePos);
}

void Figure::onMouseReleased(const QPoint &mousePos) {
    if (isSelected)
        return;
    Tool::onMouseReleased(mousePos);
}

FigureData Figure::getData() {
    return model->getData();
}

void Figure::onItemSelected() {
    isSelected = true;
    qDebug() << "item Selected";
    emit selected(this);
}

void Figure::onItemDeselected() {
    isSelected = false;
    emit deselected();
}