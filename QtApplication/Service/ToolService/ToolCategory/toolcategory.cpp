#include "toolcategory.h"
#include "../../../logger.h"

#include <utility>

ToolCategory::ToolCategory(const QString &name, IToolCategoryModel *model) : ToolUnit(name),
                                                                             view(new ToolCategoryView(name)),
                                                                             model(model) {
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
