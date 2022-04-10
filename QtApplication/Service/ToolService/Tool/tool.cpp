#include "tool.h"

#include <utility>

Tool::Tool(QString name, ToolUnitView *newView, IToolModel *newModel) : ToolUnit(std::move(name)), view(newView), model(newModel) {
    connect(view->getAction(), SIGNAL(triggered(bool)), this, SLOT(onActionTriggered()));
}

void Tool::mousePressed(const QPoint &mousePos, IGraphicsView *graphicsView) {
    model->mousePressed(mousePos, graphicsView);
}

void Tool::mouseMoved(const QPoint &mousePos, IGraphicsView *graphicsView) {
    model->mouseMoved(mousePos, graphicsView);
}

void Tool::mouseReleased(const QPoint &mousePos, IGraphicsView *graphicsView) {
    model->mouseReleased(mousePos, graphicsView);
}

QAction *Tool::getAction() {
    return view->getAction();
}

void Tool::onActionTriggered() {
    emit triggered(toString());
}
