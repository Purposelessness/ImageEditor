#include "toolunit.h"

#include <utility>

ToolUnit::ToolUnit(QString name) : name(std::move(name)), enabled(false) {}

void ToolUnit::setActive(bool value) {
    enabled = value;
}

QString ToolUnit::toString() const {
    return name;
}
