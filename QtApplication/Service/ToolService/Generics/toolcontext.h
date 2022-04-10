#ifndef IMAGEEDITOR_TOOLCONTEXT_H
#define IMAGEEDITOR_TOOLCONTEXT_H


#include "toolcontextobject.h"
#include "../../../Core/StateMachine/context.h"
#include "toolunit.h"

#include <QObject>

template<typename T>
class ToolContext : protected Context<T>, IToolContext {
public:
    void addToolUnit(T *toolUnit);
    void setToolUnit(const QString &name) override;

    ToolContextObject *object = new ToolContextObject(this);
};

#include "toolcontext.inl"


#endif //IMAGEEDITOR_TOOLCONTEXT_H
