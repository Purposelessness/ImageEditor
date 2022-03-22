#include "toolcategory.h"
#include "../../logger.h"

#include <utility>

ToolCategory::ToolCategory(QString name, ToolCategoryView *view, ToolCategoryModel *model) : ToolUnit(std::move(name)),
                                                                                             view(view), model(model) {
    connectSignals();
    model->createTools();
}

void ToolCategory::connectSignals() {
    connect(model, SIGNAL(toolAdded(QAction*)), this, SLOT(onToolAdded(QAction*)));
    connect(view->getAction(), SIGNAL(triggered(bool)), this, SLOT(onActionTriggered()));
    connect(model, SIGNAL(toolChanged()), this, SLOT(onToolChanged()));
    connect(model, SIGNAL(toolWidgetEnabled(bool)), this, SLOT(onToolWidgetEnabled(bool)));
}

QAction *ToolCategory::getAction() {
    return view->getAction();
}

QWidget *ToolCategory::getWidget() {
    return toolWidgetState ? model->getCurrentToolWidget() : view->getWidget();
}

IToolModel *ToolCategory::getToolModel() {
    return model->getCurrentToolModel();
}

void ToolCategory::onToolAdded(QAction *action) {
    view->addToolAction(action);
}

void ToolCategory::onActionTriggered() {
    emit toolTriggered(toString());
}

void ToolCategory::onToolChanged() {
    emit toolChanged();
}

void ToolCategory::onToolWidgetEnabled(bool value) {
    toolWidgetState = value;
    emit toolWidgetEnabled(value);
}

