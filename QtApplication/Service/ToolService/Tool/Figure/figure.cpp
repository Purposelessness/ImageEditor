#include "figure.h"

Figure::Figure(const QString &name, FigureModel *model) : Tool(name, model), model(model) {
    connect(model, SIGNAL(itemSelected()), this, SLOT(onItemSelected()));
    connect(model, SIGNAL(itemDeselected()), this, SLOT(onItemDeselected()));
}

void Figure::onMousePressed(const QPoint &mousePos, IGraphicsView *graphicsView) {
    if (isSelectedFlag)
        return;
    emit update(this);
    Tool::onMousePressed(mousePos, graphicsView);
}

void Figure::onMouseMoved(const QPoint &mousePos) {
    if (isSelectedFlag)
        return;
    Tool::onMouseMoved(mousePos);
}

void Figure::onMouseReleased(const QPoint &mousePos) {
    if (isSelectedFlag)
        return;
    Tool::onMouseReleased(mousePos);
}

FigureData Figure::getData() const {
    return model->getData();
}

void Figure::onItemSelected() {
    prevItemWasSelected = isSelectedFlag;
    isSelectedFlag = true;
    emit selected(this);
}

void Figure::onItemDeselected() {
    if (prevItemWasSelected) {
        prevItemWasSelected = false;
        return;
    }
    isSelectedFlag = false;
    emit deselected();
}

bool Figure::isSelected() const {
    return isSelectedFlag;
}
