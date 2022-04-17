#include "tool.h"

Tool::Tool(const QString &name, ToolModel *newModel) : ToolUnit(name), view(new ToolUnitView(name)), model(newModel) {
    connect(view->getAction(), SIGNAL(triggered(bool)), this, SLOT(onActionTriggered()));
}

void Tool::onMousePressed(const QPoint &mousePos, IGraphicsView *graphicsView) {
    model->onMousePressed(mousePos, graphicsView);
}

void Tool::onMouseMoved(const QPoint &mousePos) {
    model->onMouseMoved(mousePos);
}

void Tool::onMouseReleased(const QPoint &mousePos) {
    model->onMouseReleased(mousePos);
}

QAction *Tool::getAction() {
    return view->getAction();
}

void Tool::onActionTriggered() {
    emit triggered(toString());
}
