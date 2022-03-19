#include "toolunit.h"

#include <utility>

ToolUnit::ToolUnit(QString name) : name(std::move(name)), enabled(false) {}

QString ToolUnit::toString() const {
    return name;
}
