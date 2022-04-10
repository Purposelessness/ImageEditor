#include "toolcontextobject.h"

ToolContextObject::ToolContextObject(IToolContext *newSelf) : self(newSelf) {}

void ToolContextObject::setToolUnit(const QString &name) {
    self->setToolUnit(name);
}