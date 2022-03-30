#include "shape.h"

#include <utility>

Shape::Shape(QString name, ToolUnitView *view, ShapeModel *model) : Tool(std::move(name), view, model) {}

void Shape::update() {

}
