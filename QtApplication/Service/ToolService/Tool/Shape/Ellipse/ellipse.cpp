#include "ellipse.h"

#include <utility>

Ellipse::Ellipse(QString name, ToolUnitView *view, ShapeModel *model) : Shape(std::move(name), view, model) {
}
