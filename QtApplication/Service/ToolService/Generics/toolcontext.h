#ifndef IMAGEEDITOR_TOOLCONTEXT_H
#define IMAGEEDITOR_TOOLCONTEXT_H


#include "../../../Core/StateMachine/context.h"
#include "toolunit.h"

#include <QObject>

template<typename T, typename F>
class ToolContext : protected Context<T> {};

template<typename T>
class ToolContext<T, ToolUnit> : protected Context<T>, protected QObject {
Q_OBJECT

public:
    void addToolUnit(ToolUnit *toolUnit);

public slots:
    void setToolUnit(const QString &name);
};


#endif //IMAGEEDITOR_TOOLCONTEXT_H
