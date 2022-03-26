#include "toolunit.h"

#include <utility>

ToolUnit::ToolUnit(QString name) : name(std::move(name)) {}

QString ToolUnit::toString() const {
    return name;
}
