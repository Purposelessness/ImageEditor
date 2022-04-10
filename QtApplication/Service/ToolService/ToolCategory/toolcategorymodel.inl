#include "../../../logger.h"

template<typename T>
ToolCategoryModel<T>::ToolCategoryModel() {
    static_assert(std::is_base_of<Tool, T>::value, "Class must derive from Tool");
}

template<typename T>
void ToolCategoryModel<T>::addTool(T *newTool) {
    ToolContext<T>::addToolUnit(newTool);
    emit object->toolAdded(newTool->getAction());
}

template<typename T>
void ToolCategoryModel<T>::setTool(const QString &name) {
    ToolContext<T>::setToolUnit(name);
}

template<typename T>
T *ToolCategoryModel<T>::getTool() {
    return Context<T>::getState();
}
