#include "pen.h"

Pen::Pen(const QString &name) : Tool(name, new ToolUnitView(name, Q_NULLPTR), new PenModel()) {}
