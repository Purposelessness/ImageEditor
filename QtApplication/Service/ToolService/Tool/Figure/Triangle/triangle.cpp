#include "triangle.h"

#include <utility>

Triangle::Triangle(QString name, ToolUnitView *view, TriangleModel *model) : Shape(std::move(name), view, model) {}
