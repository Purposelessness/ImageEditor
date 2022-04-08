#include "toolcategorymodel.h"
#include "../../../logger.h"

template<typename T>
void ToolCategoryModel<T, Tool>::addTool(Tool *newTool) {
    ToolContext<T, ToolUnit>::addToolUnit(newTool);
    emit toolAdded(newTool->getAction());
}

template<typename T>
void ToolCategoryModel<T, Tool>::setTool(const QString &name) {
    ToolContext<T, ToolUnit>::setToolUnit(name);
}

template<typename T>
T *ToolCategoryModel<T, Tool>::getTool() {
    return Context<T>::getState();
}
