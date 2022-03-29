#include "tool.h"

#include <utility>

Tool::Tool(QString name, ToolUnitView *view, IToolModel *model) : ToolUnit(std::move(name)), view(view),
                                                                  model(model) {
    connect(view->getAction(), SIGNAL(triggered(bool)), this, SLOT(onActionTriggered()));
}

QAction *Tool::getAction() {
    return view->getAction();
}

QWidget *Tool::getWidget() {
    return view->getWidget();
}

IToolModel *Tool::getModel() {
    return model;
}

void Tool::onActionTriggered() {
    emit triggered(toString());
}
