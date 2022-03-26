#include "toolcategorymodel.h"
#include "../../../logger.h"

QWidget *ToolCategoryModel::getCurrentToolWidget() {
    return currentToolWidget;
}

void ToolCategoryModel::addTool(Tool *tool) {
    ToolContext::addTool(tool);
    emit toolAdded(tool->getAction());
}

void ToolCategoryModel::onToolTriggered(const QString &name) {
    ToolContext::onToolTriggered(name);
    currentToolWidget = getCurrentTool()->getWidget();
    emit toolChanged();
}

void ToolCategoryModel::onToolWidgetEnabled(bool value) {
    emit toolWidgetEnabled(value);
}
