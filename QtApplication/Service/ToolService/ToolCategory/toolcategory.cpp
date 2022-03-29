#include "toolcategory.h"
#include "../../../logger.h"

#include <utility>

ToolCategory::ToolCategory(QString name, ToolCategoryView *view, ToolCategoryModel *model) : ToolUnit(std::move(name)),
                                                                                             view(view), model(model) {
    connect(model, SIGNAL(toolAdded(QAction*)), this, SLOT(onToolAdded(QAction*)));
    connect(view->getAction(), SIGNAL(triggered(bool)), this, SLOT(onActionTriggered()));
    connect(model, SIGNAL(toolWidgetEnabled(bool)), this, SLOT(onToolWidgetEnabled(bool)));
    model->createTools();
}

QAction *ToolCategory::getAction() {
    return view->getAction();
}

QWidget *ToolCategory::getWidget() {
    return view->getWidget();
}

IToolModel *ToolCategory::getModel() {
    return model->getCurrentToolModel();
}

void ToolCategory::onToolAdded(QAction *action) {
    view->addToolAction(action);
}

void ToolCategory::onActionTriggered() {
    emit triggered(toString());
}

QWidget *ToolCategory::getAlternativeWidget() {
    return ToolUnit::getAlternativeWidget();
}
