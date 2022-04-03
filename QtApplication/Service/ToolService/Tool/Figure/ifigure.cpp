#include "ifigure.h"

#include <utility>

IFigure::IFigure(QString name, ToolUnitView *view, IToolModel *model) : Tool(std::move(name), view, model) {}
