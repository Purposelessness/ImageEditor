#include "toolcategory.h"
#include "../../../logger.h"

#include <utility>

ToolCategory::ToolCategory(QString name, ToolCategoryView *view, IToolCategoryModel *model) : ToolUnit(std::move(name)),
                                                                                              view(view), model(model) {
    connect(model->object, SIGNAL(toolAdded(QAction*)), this, SLOT(onToolAdded(QAction*)));
    connect(view->getAction(), SIGNAL(triggered(bool)), this, SLOT(onActionTriggered()));
    model->createTools();
}

QAction *ToolCategory::getAction() {
    return view->getAction();
}

QWidget *ToolCategory::getWidget() {
    return view->getWidget();
}

Tool *ToolCategory::getTool() {
    return model->getTool();
}

void ToolCategory::onToolAdded(QAction *action) {
    view->addToolAction(action);
}

void ToolCategory::onActionTriggered() {
    emit triggered(toString());
}
