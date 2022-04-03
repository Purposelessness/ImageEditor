#include "toolcategorymodel.h"
#include "../../../logger.h"

void ToolCategoryModel::addTool(Tool *tool) {
    ToolContext::addTool(tool);
    emit toolAdded(tool->getAction());
}

void ToolCategoryModel::setTool(const QString &name) {
    ToolContext::setTool(name);
}
