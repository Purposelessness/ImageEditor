#include "rect.h"

#include <utility>

Rect::Rect(QString name, ToolUnitView *view, ShapeModel *model) : Shape(std::move(name), view, model) {
}
