#include "figure.h"

#include <utility>

Figure::Figure(QString name, ToolUnitView *view, IToolModel *model) : Tool(std::move(name), view, model) {}
