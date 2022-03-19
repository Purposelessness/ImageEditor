#include "brush.h"

Brush::Brush(const QString& name) : Tool(name, new ToolUnitView(name, Q_NULLPTR), new BrushModel()) {}
