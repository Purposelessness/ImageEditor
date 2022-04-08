#include "toolcontext.h"

template<typename T>
void ToolContext<T, ToolUnit>::addToolUnit(ToolUnit *toolUnit) {
    Context<ToolUnit>::addState(toolUnit->toString(), toolUnit);
    connect(toolUnit, SIGNAL(triggered(QString)), this, SLOT(setToolUnit(QString)));
}

template<typename T>
void ToolContext<T, ToolUnit>::setToolUnit(const QString &name) {
    Context<ToolUnit>::setState(name);
}